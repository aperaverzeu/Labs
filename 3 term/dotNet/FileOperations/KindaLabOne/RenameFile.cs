using System;
using System.IO;

namespace KindaLabOne
{
    public class RenameFile : ICommand
    {
        private readonly string _path;

        public RenameFile(string path)
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
                    Console.WriteLine("Enter a new name via path to a file:");
                    fileInformation.MoveTo(Program.WriteToPath());
                }
                else
                    Console.WriteLine("Sorry, we're couldn't rename this file cuz it doesn't exist");
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
                throw;
            }
        }
    }
}