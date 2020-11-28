using System;
using System.IO;

namespace KindaLabOne
{
    public class WriteFile : ICommand
    {
        private readonly string _path;

        public WriteFile(string path)
        {
            _path = path;
        }


        public void Execute()
        {
            Console.WriteLine("Enter some info to write in a file:");
            var text = Console.ReadLine();
            try
            {
                var fileInformation = new FileInfo(_path);
                if (fileInformation.Exists)
                {
                    using var writer = new StreamWriter(_path, true, System.Text.Encoding.Default);
                    writer.WriteLine(text);


                    // using var stream = new FileStream("/Users/alex/Desktop/folder/test.txt", FileMode.OpenOrCreate);
                    // var array = System.Text.Encoding.Default.GetBytes(text);
                    // stream.Write(array, 0, array.Length);
                    Console.WriteLine("Working!");
                }
                else
                    Console.WriteLine("Sorry, we're couldn't write some information in this file cuz it doesn't exist");
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
                throw;
            }
        }
    }
}
