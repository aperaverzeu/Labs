using System;
using System.IO;

namespace KindaLabOne
{
    public class DeleteFile : ICommand
    { 
        private readonly string _path;

        public DeleteFile(string path)
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
                    fileInformation.Delete();
                }
                else
                    Console.WriteLine("Sorry, we're couldn't delete this file cuz it doesn't exist");
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
                throw;
            }
        }
    }
}
