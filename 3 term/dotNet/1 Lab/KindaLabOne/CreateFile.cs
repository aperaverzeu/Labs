using System;
using System.IO;

namespace KindaLabOne
{
    public class CreateFile : ICommand
    {
        private readonly string _path;

        public CreateFile(string path)
        {
            _path = path;
        }

        public void Execute()
        {
            try
            {
                if (!File.Exists(_path))
                {
                    // Create a file to write to.
                    using var sw = File.CreateText(_path);
                    sw.WriteLine("Hello");
                    sw.WriteLine("And");
                    sw.WriteLine("Welcome");
                    Console.WriteLine("Hej!");
                }
                else
                    Console.WriteLine("Sorry, file with this name is already exists");
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
                throw;
            }
        }
    }
}