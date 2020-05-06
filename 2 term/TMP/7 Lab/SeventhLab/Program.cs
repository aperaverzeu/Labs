using System;
using System.Globalization;

namespace SeventhLab
{
    class Program
    {
        static void Main(string[] args)
        {
            //Constructor tests
            Console.WriteLine("\nConstructor tests: \n");

            RationalNumber rn1 = new RationalNumber(10, 3);
            Console.WriteLine(rn1);

            RationalNumber rn2 = new RationalNumber(12, 0);
            Console.WriteLine(rn2);


            //Math operators & operations tests
            Console.WriteLine("\nMath operators & operations tests : \n");

            RationalNumber sum = rn1 + rn2;
            Console.WriteLine(sum);

            RationalNumber sub = rn1 - rn2;
            Console.WriteLine(sub);

            RationalNumber mult = rn1 * rn2;
            Console.WriteLine(mult);

            RationalNumber div = rn1 / rn2;
            Console.WriteLine(mult);


            //Compare operators & operations tests
            Console.WriteLine("\nCompare operators & operations tests : \n");

            Console.WriteLine(rn1 > rn2);
            Console.WriteLine(rn1 < rn2);
            Console.WriteLine(rn1 >= rn2);
            Console.WriteLine(rn1 <= rn2);
            Console.WriteLine(rn1 == rn2);
            Console.WriteLine(rn1 != rn2);
            Console.WriteLine(sum.GetHashCode());



            //Reduce method test
            Console.WriteLine("\nReduce method test : \n");

            RationalNumber red = sum.Reduce();
            Console.WriteLine(red);


            //Convert methods tests
            Console.WriteLine("\nConvert methods tests : \n");

            var provider = CultureInfo.CurrentCulture;

            TypeCode typeCode = rn1.GetTypeCode();
            Console.WriteLine(typeCode);

            bool toBool = rn1.ToBoolean(provider);
            Console.WriteLine(toBool);

            byte toByte = rn1.ToByte(provider);
            Console.WriteLine(toByte);

            char toChar = rn1.ToChar(provider);
            Console.WriteLine(toChar);

            DateTime toDT = rn1.ToDateTime(provider);
            Console.WriteLine(toDT);

            decimal toDecimal = rn1.ToDecimal(provider);
            Console.WriteLine(toDecimal);

            double toDouble = rn1.ToDouble(provider);
            Console.WriteLine(toDouble);

            Int16 toInt16 = rn1.ToInt16(provider);
            Console.WriteLine(toInt16);

            Int32 toInt32 = rn1.ToInt32(provider);
            Console.WriteLine(toInt32);

            Int64 toInt64 = rn1.ToInt64(provider);
            Console.WriteLine(toInt64);

            SByte toSByte = rn1.ToSByte(provider);
            Console.WriteLine(toSByte);

            Single toSingle = rn1.ToSingle(provider);
            Console.WriteLine(toSingle);

            UInt16 toUInt16 = rn1.ToUInt16(provider);
            Console.WriteLine(toUInt16);

            UInt32 toUInt32 = rn1.ToUInt32(provider);
            Console.WriteLine(toUInt32);

            UInt64 toUInt64 = rn1.ToUInt64(provider);
            Console.WriteLine(toUInt64);

            ulong toType = (ulong)rn1.ToType(typeof(ulong), provider);
            Console.WriteLine(toType);



            //Convert operators tests
            Console.WriteLine("\nConvert operators tests : \n");

            //explisit
            Console.WriteLine((int)rn1);
            Console.WriteLine((long)rn1);
            Console.WriteLine((decimal)rn1);
            Console.WriteLine((double)rn1);
            Console.WriteLine((float)rn1);

            //implisit
            int testInt = 10;
            RationalNumber testIntRn = testInt;
            Console.WriteLine(testIntRn);

            long testLong = 10;
            RationalNumber testLongRn = testLong;
            Console.WriteLine(testLongRn);

            decimal testDecimal = 10.2m;
            RationalNumber testDecimalRn = testDecimal;
            Console.WriteLine(testDecimalRn);

            double testDouble = 10.2;
            RationalNumber testDoubleRn = testDouble;
            Console.WriteLine(testDoubleRn);

            float testFloat = 10.2f;
            RationalNumber testFloatRn = testFloat;
            Console.WriteLine(testFloatRn);


            //Format tests
            Console.WriteLine("\nFormat tests : \n");

            Console.WriteLine(rn1.ToString("F"));
            Console.WriteLine(rn1.ToString("D"));
            Console.WriteLine(rn1.ToString("P"));
            Console.WriteLine(rn1.ToString("N"));

            try
            {
                Console.WriteLine(rn1.ToString("None"));
            }
            catch (Exception e)
            {

                Console.WriteLine("Exception: " + e.Message);
            }


            //TryParse tests
            Console.WriteLine("\nTryParse tests : \n");
            RationalNumber rnTryParseTesting;
            Console.WriteLine(RationalNumber.TryParse("not number", out rnTryParseTesting));
            Console.WriteLine(RationalNumber.TryParse("30/34", out rnTryParseTesting));
            Console.WriteLine(RationalNumber.TryParse("30", out rnTryParseTesting));
            Console.WriteLine(RationalNumber.TryParse("30,34", out rnTryParseTesting));
        }
    }
}
