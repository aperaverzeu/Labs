using System;
using System.IO;

namespace KindaLabOne
{
    public class ReadFile : ICommand
    {
        private readonly string _path;

        public ReadFile(string path)
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
                    using var stream = File.OpenRead(_path);
                    var array = new byte[stream.Length];
                    stream.Read(array, 0, array.Length);
                    var textFromFile = System.Text.Encoding.Default.GetString(array);
                    Console.WriteLine($"Text from file:\n {textFromFile}");
                }
                else
                    Console.WriteLine("Sorry, we're couldn't read some information from this file cuz it doesn't exist");
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
                throw;
            }
        }
    }
}
