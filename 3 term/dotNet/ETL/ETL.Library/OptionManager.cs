using System;
using System.IO;
using ETL.Options;

namespace ETL.Library
{
    public class OptionManager
    {
        private readonly EtlOptions _defaultOptions;
        private readonly EtlJsonOptions _json;
        private readonly EtlXmlOptions _xml;
        private readonly bool _jsonConfigured, _xmlConfigured;
        public string Report { get; } = "";

        public OptionManager(string path)
        {
            _defaultOptions = new EtlOptions();
            string options;
            try
            {
                using(var xmlReader = new StreamReader($"{path}/config.xml"))
                {
                    options = xmlReader.ReadToEnd();
                }
                _xml = new EtlXmlOptions(options);
                _xmlConfigured = true;
                Report = _xml.Report;
                Report += "Xml options loaded successfully. ";
                // logger.Log(Report);
            }
            catch
            {
                _xmlConfigured = false;
            }
            try
            {
                using(var jsonReader = new StreamReader($"{path}/appsettings.json"))
                {
                    options = jsonReader.ReadToEnd();
                }
                _json = new EtlJsonOptions(options);
                _jsonConfigured = true;
                Report = _json.Report;
                Report += "Json options loaded successfully. ";
                // logger.Log(Report);
            }
            catch
            {
                _jsonConfigured = false;
            }
            if(!_jsonConfigured && !_xmlConfigured)
            {
                Report = "Failed to load both of json and xml. Using default options and creating appsettings.json";
                // logger.Log(Report);
                if(!File.Exists($"{path}/appsettings.json"))
                {
                    var json = Converter.SerializeJson(_defaultOptions);
                    Validator.CreateDirectoryIfNotExist(path);
                    using var appsettings = new StreamWriter($"{path}/appsettings.json");
                    appsettings.Write(json);
                }
                if(!File.Exists($"{path}/config.xml"))
                {
                    var xml = Converter.SerializeXml(_defaultOptions);
                    Validator.CreateDirectoryIfNotExist(path);
                    using var configXml = new StreamWriter($"{path}/config.xml");
                    configXml.Write(xml);
                }
            }
        }
        
        public Options.Options GetOptions<T>()
        {
            return _jsonConfigured ? SeekForOption<T>(_json) : SeekForOption<T>(_xmlConfigured ? _xml : _defaultOptions);
        }

        private static Options.Options SeekForOption<T>(EtlOptions options)
        {
            if(typeof(T) == typeof(EtlOptions))
            {
                return options;
            }
            var name = typeof(T).Name;
            try
            {
                return options.GetType().GetProperty(name)?.GetValue(options, null) as Options.Options;
            }
            catch
            {
                throw new NotImplementedException();
            }
        }
    }
}