using System;
using System.IO;

namespace KindaLabOne
{
    public class InfoFile : ICommand
    {
        private readonly string _path;

        public InfoFile(string path)
        {
            _path = path;
        }

        public void Execute()
        {
            try
            {
                var fileInformation = new FileInfo(_path);
                if (fileInformation.Exists)
                {
                    Console.WriteLine("File name: {0}", fileInformation.Name);
                    Console.WriteLine("Čas utvareńnia: {0}", fileInformation.CreationTime);
                    Console.WriteLine("Size: {0} byte(s)", fileInformation.Length);
                }
                else
                    Console.WriteLine("Sorry, we're missing some info 'bout this file cuz it doesn't exist");
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
                throw;
            }
        }
    }
}
