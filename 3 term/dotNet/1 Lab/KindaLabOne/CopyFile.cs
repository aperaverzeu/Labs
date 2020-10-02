using System;
using System.IO;

namespace KindaLabOne
{
    public class CopyFile : ICommand
    {
        private readonly string _path;
        private readonly string _newPath;

        public CopyFile(string path, string newPath)
        {
            _path = path;
            _newPath = newPath;
        }

        public void Execute()
        {
            try
            {
                var fileInformation = new FileInfo(_path);
                if (fileInformation.Exists)
                {
                    fileInformation.CopyTo(_newPath, true);
                }
                else
                    Console.WriteLine("Sorry, we're couldn't copy this file cuz it doesn't exist");
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
                throw;
            }
        }
    }
}
