using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Text.RegularExpressions;

namespace ETL.Options
{
    public static class Converter
    {
        public static T DeserializeJson<T>(string json)
        {
            var objects = ParseJson(json);
            return Deserialize<T>(objects);
        }

        public static T DeserializeXml<T>(string xml)
        {
            var objects = ParseXml(xml, true);
            return Deserialize<T>(objects);
        }

        private static T Deserialize<T>(IReadOnlyCollection<ParsedObject> objects)
        {
            var type = typeof(T);

            if(objects.Count == 1 && objects.First().Key == "")
            {
                switch (objects.First().Type)
                {
                    case ParsedObject.ObjectType.SimpleObject:
                        return (T)Convert.ChangeType(objects.First().Value.Trim('\"'), type);
                    case ParsedObject.ObjectType.Array when IsArray(type):
                    {
                        var typeOfList = type.GenericTypeArguments.Length == 0 ? type.GetElementType() : type.GenericTypeArguments[0];
                        var list = ParseArray(typeOfList, objects.First());
                        return (T)ConvertToArray(list, type);
                    }
                    case ParsedObject.ObjectType.Array:
                        throw new Exception("This string can't be parsed into this type");
                    case ParsedObject.ObjectType.ComplexObject:
                        break;
                    case ParsedObject.ObjectType.XmlComplex:
                        break;
                    case ParsedObject.ObjectType.XmlArray:
                        break;
                    default:
                        throw new ArgumentOutOfRangeException();
                }
            }
            if(IsArray(type))
            {
                var typeOfList = type.GenericTypeArguments.Length == 0 ? type.GetElementType() : type.GenericTypeArguments[0];
                if(objects.Count > 0)
                {
                    objects.First().Type = ParsedObject.ObjectType.XmlArray;
                    var list = ParseArray(typeOfList, objects.First());
                    return (T)ConvertToArray(list, type);
                }
            }
            var ans = (T)Activator.CreateInstance(type);

            foreach(var parsedObject in objects)
            {
                var key = parsedObject.Key;
                var value = parsedObject.Value.Trim('\"');
                var memberType = GetMemberType(type, key);
                switch (parsedObject.Type)
                {
                    case ParsedObject.ObjectType.SimpleObject:
                    {
                        var converted = memberType.IsEnum ? Enum.Parse(memberType, value) : Convert.ChangeType(value, memberType);
                        SetMemberValue(ans, key, converted);
                        break;
                    }
                    case ParsedObject.ObjectType.ComplexObject:
                    {
                        var parsed = typeof(Converter)
                            .GetMethod("Deserialize", BindingFlags.NonPublic | BindingFlags.Static)
                            ?.MakeGenericMethod(memberType)
                            .Invoke(null, new object[] { ParseJson(value) });
                        SetMemberValue(ans, key, parsed);
                        break;
                    }
                    case ParsedObject.ObjectType.XmlComplex when IsArray(GetMemberType(type, key)):
                        SetArrayValue(ans, key, parsedObject);
                        break;
                    case ParsedObject.ObjectType.XmlComplex:
                    {
                        var parsed = typeof(Converter)
                            .GetMethod("Deserialize", BindingFlags.NonPublic | BindingFlags.Static)
                            ?.MakeGenericMethod(memberType)
                            .Invoke(null, new object[] { ParseXml(value, false) });
                        SetMemberValue(ans, key, parsed);
                        break;
                    }
                    case ParsedObject.ObjectType.Array:
                        break;
                    case ParsedObject.ObjectType.XmlArray:
                        break;
                    default:
                    {
                        if(IsArray(memberType))
                        {
                            SetArrayValue(ans, key, parsedObject);
                        }
                        break;
                    }
                }
            }
            return ans;
        }

        public static string SerializeJson(object obj)
        {
            return SerializeJson(obj, 0).Trim('\n');
        }

        private static string SerializeJson(object obj, int deep)
        {
            var type = obj.GetType();
            StringBuilder sb;
            if(type.GetCustomAttribute(typeof(JsonIgnore)) != null)
            {
                return "";
            }
            if(type.IsPrimitive || type.IsEnum)
            {
                sb = new StringBuilder($"{obj}");
            }
            else if(type == typeof(string))
            {
                sb = new StringBuilder($"\"{obj}\"");
            }
            else if(IsArray(type))
            {
                var isComplex = false;
                sb = new StringBuilder("");
                var i = 0;
                var length = ((IEnumerable)obj).Length();
                foreach(var o in (IEnumerable)obj)
                {
                    var value = $"{SerializeJson(o, deep + 1)}";
                    if(value.Trim('\n', '\t', ' ').First() == '{')
                    {
                        isComplex = true;
                    }
                    if(i < length - 1)
                    {
                        value = value.TrimEnd('\n');
                        value += ",";  
                    }
                    sb.Append(value);
                    i++;
                }
                if(isComplex)
                {
                    sb.Insert(0, $"\n{new string('\t', deep)}[");
                    sb.AppendLine();
                    sb.Append($"{new string('\t', deep)}]");
                }
                else
                {
                    sb.Insert(0, "[");
                    sb.Append("]");
                }
            }
            else
            {
                sb = new StringBuilder($"\n{new string('\t', deep)}{{\n");
                MemberInfo[] members = type.GetProperties();
                members = members.Concat(type.GetFields()).ToArray();
                
                for(var i = 0; i < members.Length; i++)
                {
                    if(members[i].GetCustomAttribute(typeof(JsonIgnore)) != null)
                    {
                        continue;
                    }
                    var o = GetMemberValue(obj, members[i].Name);
                    var value = $"{SerializeJson(o, deep + 1)}";
                    sb.Append($"{new string('\t', deep + 1)}{members[i].Name} : {value}".TrimEnd('\n'));
                    if(i != members.Length - 1)
                    {
                        sb.Append(',');
                    }
                    sb.AppendLine();
                }
                sb.Append($"{new string('\t', deep)}}}\n");
            }
            return sb.ToString();
        }

        public static string SerializeXml(object obj)
        {
            return SerializeXml(obj, 0, "");
        }

        private static string SerializeXml(object obj, int deep, string name)
        {
            var type = obj.GetType();
            StringBuilder sb;
            if(type.GetCustomAttribute(typeof(XmlIgnore)) != null)
            {
                return "";
            }
            if(type.IsPrimitive || type.IsEnum || type == typeof(string))
            {
                name = name == "" ? type.Name : name;
                sb = new StringBuilder($"{new string('\t', deep)}<{name}>{obj}</{name}>\n");
            }
            else if(IsArray(type))
            {
                var arrayType = type.GenericTypeArguments.Length == 0 ? 
                    type.GetElementType() : 
                    type.GenericTypeArguments[0];
                if(name == "")
                {
                    name = $"ArrayOf{arrayType?.Name}";
                }
                sb = new StringBuilder($"{new string('\t', deep)}<{name}>\n");
                var typeName = arrayType?.Name;
                //sb = new StringBuilder();//$"{new string('\t', deep)}<{name}>");
                foreach(var o in (IEnumerable)obj)
                {
                    sb.Append(SerializeXml(o, deep + 1, typeName));
                }
                sb.AppendLine($"{new string('\t', deep)}</{name}>");
            }
            else
            {
                name = name == "" ? type.Name : name;
                sb = new StringBuilder($"{new string('\t', deep)}<{name}>\n");
                MemberInfo[] members = type.GetProperties();
                members = members.Concat(type.GetFields()).ToArray();

                for(var i = 0; i < members.Length; i++)
                {
                    if(members[i].GetCustomAttribute(typeof(XmlIgnore)) != null)
                    {
                        continue;
                    }
                    var o = GetMemberValue(obj, members[i].Name);
                    var value = SerializeXml(o, deep + 1, members[i].Name);
                    if(i == members.Length - 1)
                    {
                        value = value.TrimEnd('\t', '\n', ' ');
                    }
                    sb.Append(value);
                }
                sb.AppendLine($"\n{new string('\t', deep)}</{name}>");
            }
            return sb.ToString();
        }

        private static IList ParseArray(Type type, ParsedObject obj)
        {
            var listType = typeof(List<>).MakeGenericType(type);
            var list = Activator.CreateInstance(listType) as IList;
            var methodName = "";
            switch (obj.Type)
            {
                case ParsedObject.ObjectType.XmlComplex:
                    methodName = "DeserializeXml";
                    obj = ParseXml(obj.Value, false).First();
                    break;
                case ParsedObject.ObjectType.Array:
                    methodName = "DeserializeJson";
                    break;
                case ParsedObject.ObjectType.SimpleObject:
                    break;
                case ParsedObject.ObjectType.ComplexObject:
                    break;
                case ParsedObject.ObjectType.XmlArray:
                    break;
                default:
                    methodName = "DeserializeXml";
                    break;
            }
            foreach(var v in obj.ValueArray)
            {
                list?.Add(typeof(Converter).GetMethod(methodName!)
                    ?.MakeGenericMethod(type)
                                          .Invoke(null, new object[] { v.Trim() }));
            }
            return list;
        }

        private static Type GetMemberType(Type type, string memberName)
        {
            var memberType = type.GetProperty(memberName)?.PropertyType;
            if(memberType == null)
            {
                memberType = type.GetField(memberName)?.FieldType;
            }
            if(memberType == null)
            {
                throw new Exception("This type doesn't contain member with this name");
            }
            return memberType;
        }

        private static object ConvertToArray(ICollection list, Type type)
        {
            var typeOfList = type.GenericTypeArguments.Length == 0 ? type.GetElementType() : type.GenericTypeArguments[0];
            if(type.IsArray)
            {
                var array = Array.CreateInstance(typeOfList!, list.Count);
                list.CopyTo(array, 0);
                return array;
            }

            var ie = typeof(IEnumerable<>).MakeGenericType(typeOfList!);
            var con = type.GetConstructor(new[] { ie });
            if(con != null)
            {
                return Activator.CreateInstance(type, list);
            }

            throw new Exception("This list cannot be converted to this type");
        }

        private static void SetArrayValue(object obj, string memberName, ParsedObject parsedObject)
        {
            var memberType = GetMemberType(obj.GetType(), memberName);
            var typeOfList = memberType.GenericTypeArguments.Length == 0 ? memberType.GetElementType() : memberType.GenericTypeArguments[0];
            var list = ParseArray(typeOfList, parsedObject);
            var converted = ConvertToArray(list, GetMemberType(obj.GetType(), memberName));
            SetMemberValue(obj, memberName, converted);
        }

        private static object GetMemberValue(object obj, string memberName)
        {
            var type = obj.GetType();
            if(type.GetProperty(memberName) != null)
            {
                var info = type.GetProperty(memberName);
                return info?.GetValue(obj);
            }

            if(type.GetField(memberName) != null)
            {
                var info = type.GetField(memberName);
                return info?.GetValue(obj);
            }

            throw new Exception("This type doesn't contain member with this name");
        }

        private static void SetMemberValue(object obj, string memberName, object value)
        {
            var type = obj.GetType();
            if(type.GetProperty(memberName) != null)
            {
                var info = type.GetProperty(memberName);
                info?.SetValue(obj, value);
            }
            else if(type.GetField(memberName) != null)
            {
                var info = type.GetField(memberName);
                info?.SetValue(obj, value);
            }
            else
            {
                throw new Exception("This type doesn't contain member with this name");
            }
            
        }

        private static int Length(this IEnumerable ie)
        {
            return ie.Cast<object>().Count();
        }

        private static List<ParsedObject> ParseJson(string json)
        {
            var objects = new List<ParsedObject>();
            var values = new List<string>();
            string key = "", value = "";
            int braces = 0, squares = 0;
            bool isKey = true, quotes = false;
            var trimming = new Regex("^\\s*{(.*)}\\s*$", RegexOptions.Singleline);
            var match = trimming.Match(json);
            if(match.Success)
            {
                json = match.Groups[1].Value;
            }
            foreach (var c in json.Where(c => char.IsLetterOrDigit(c) || char.IsPunctuation(c) || quotes))
            {
                if(c == '\"')
                {
                    quotes = !quotes;
                }
                if(quotes)
                {
                    if(isKey)
                    {
                        key += c;
                    }
                    else
                    {
                        value += c;
                    }
                    continue;
                }

                switch (c)
                {
                    case '{':
                        braces++;
                        break;
                    case '}':
                        braces--;
                        break;
                    case '[' when braces == 0:
                    {
                        squares++;
                        if(squares == 1)
                        {
                            continue;
                        }
                        break;
                    }
                    case ']' when braces == 0:
                    {
                        squares--;
                        if(squares == 0)
                        {
                            continue;
                        }
                        break;
                    }
                    case ':' when braces == 0 && squares == 0:
                        isKey = false;
                        continue;
                    case ',' when braces == 0:
                    {
                        values.Add(value);
                        value = "";
                        if(isKey)
                        {
                            value = key;
                            key = "";
                        }
                        if(squares == 0)
                        {
                            objects.Add(new ParsedObject(key, values));
                            values = new List<string>();
                            key = "";
                            value = "";
                            isKey = true;
                        }
                        continue;
                    }
                }
                if(isKey)
                {
                    key += c;
                }
                else
                {
                    value += c;
                }
            }
            if(braces == 0 && squares == 0)
            {
                if(!(key == "" && value == ""))
                {
                    if(isKey)
                    {
                        values.Add(key);
                        key = "";
                    }
                    else
                    {
                        values.Add(value);
                    }
                    objects.Add(new ParsedObject(key, values));
                } 
            }
            else
            {
                throw new Exception("Json object is incorrect");
            }
            return objects;
        }

        private static List<ParsedObject> ParseXml(string xml, bool trim)
        {
            xml = xml.Trim('\n', '\t', '\r', ' ');
            var objects = new List<ParsedObject>();
            string tagName;
            Match match;
            try
            {
                tagName = GetNextTag(xml, 0);
                if(trim)
                {
                    var trimming = new Regex($"^<{tagName}>(.*)</{tagName}>$", RegexOptions.Singleline);
                    match = trimming.Match(xml);
                    if(match.Success)
                    {
                        xml = match.Groups[1].Value;
                    }
                }
            }
            catch
            {
                return new List<ParsedObject> { new ParsedObject("", new List<string> { xml }, ParsedObject.ObjectType.SimpleObject) };
            }

            var label = new Regex(@"<(/?.*)>");

            var keyValues = new Dictionary<string, List<string>>();
            string mainTag = "", tag = "";
            var deep = 0;
            bool isMainTag = true, isValue = false;
            var value = "";
            var quotes = false;
            foreach (var c in xml.Where(c => (c != '\t' && c != '\r' && c != '\n') || quotes))
            {
                if(c == '\"')
                {
                    quotes = !quotes;
                }
                if(quotes)
                {
                    value += c;
                    continue;
                }
                switch (c)
                {
                    case '<':
                    {
                        isValue = false;
                        if(!isMainTag)
                        {
                            tag += c;
                        }
                        break;
                    }
                    case '>' when isMainTag:
                        isMainTag = false;
                        isValue = true;
                        deep++;
                        break;
                    case '>':
                    {
                        tag += c;
                        match = label.Match(tag);

                        if(match.Success)
                        {
                            tagName = match.Groups[1].Value;
                            if(tagName[0] == '/')
                            {
                                if('/' + mainTag == tagName && deep == 1)
                                {
                                    if(keyValues.ContainsKey(mainTag))
                                    {
                                        keyValues[mainTag].Add(value);
                                    }
                                    else
                                    {
                                        keyValues.Add(mainTag, new List<string> { value });
                                    }
                                    mainTag = "";
                                    tag = "";
                                    isMainTag = true;
                                    isValue = false;
                                    value = "";
                                }
                                else
                                {
                                    value += tag;
                                    tag = "";
                                    isValue = true;
                                }
                                deep--;
                            }
                            else
                            {
                                deep++;
                                isValue = true;
                                value += tag;
                                tag = "";
                            }
                        }
                        else
                        {
                            throw new Exception("File was damaged");
                        }
                        break;
                    }
                    default:
                    {
                        if(isValue)
                        {
                            value += c;
                        }
                        else if(isMainTag)
                        {
                            mainTag += c;
                        }
                        else
                        {
                            tag += c;
                        }
                        break;
                    }
                }
            }
            if(mainTag != "")
            {
                return new List<ParsedObject> { new ParsedObject("", new List<string> { mainTag }, ParsedObject.ObjectType.SimpleObject) };
            }
            foreach(var (key, list) in keyValues)
            {
                ParsedObject.ObjectType type;
                if(list.First().Length > 0 && list.First()[0] == '<')
                {
                    type = ParsedObject.ObjectType.XmlComplex;
                }
                else
                {
                    type = ParsedObject.ObjectType.SimpleObject;
                }
                objects.Add(new ParsedObject(key, list, type));
            }
            return objects;
        }

        private static string GetNextTag(string xml, int startIndex)
        {
            var tag = new StringBuilder("");
            var isTag = false;
            for(var i = startIndex; i < xml.Length; i++)
            {
                switch (xml[i])
                {
                    case '<':
                        isTag = true;
                        continue;
                    case '>':
                        return tag.ToString();
                    default:
                    {
                        if(isTag)
                        {
                            tag.Append(xml[i]);
                        }
                        break;
                    }
                }
            }
            throw new Exception("Can't find matching tag");
        }

        private static bool IsArray(Type type)
        {
            if(type == typeof(string))
            {
                return false;
            }
            return type.IsArray || type.GetInterface(nameof(IEnumerable)) != null;
        }
    }
}