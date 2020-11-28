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
                    using var writer = File.CreateText(_path);
                    Console.WriteLine("Alright slappers!");
                }
                else
                    Console.WriteLine("Sorry, we're couldn't create this file");
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
                throw;
            }
        }
    }
}
