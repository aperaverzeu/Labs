using System;
using System.Globalization;

namespace ETLibrary
{
    public static class Logger
    {
        public static void CreateFile(string file, string folder)
        {
            Console.WriteLine("Created a {0} file in {1} folder.\t |||| {2}", file, folder, DateTime.Now.ToString(CultureInfo.CurrentCulture));
        }

        public static void CreateDirectory(string folder)
        {
            Console.WriteLine("Created folder {0}\t |||| {1}", folder, DateTime.Now.ToString(CultureInfo.InvariantCulture));
        }
    }
}