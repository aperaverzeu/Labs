using System;
using System.IO;

namespace ETLibrary
{
    public class Move
    {
        private readonly string _path;
        private static string _newPath;

        public Move(string path, string newPath)
        {
            _path = path;
            _newPath = newPath;
        }

        public void Run()
        {
            var watcher = new FileSystemWatcher(_path)
            {
                Filter = "*.txt", EnableRaisingEvents = true, IncludeSubdirectories = true
            };
            
            watcher.Created += OnCreated;
            
            Console.WriteLine("Run!");
            Console.ReadLine();
        }

        private static void OnCreated(object sender, FileSystemEventArgs e)
        {
            var file = new FileInfo(e.FullPath);
            var key = Encryption.GenerateKey(16);
            var clientDirectory= _newPath +  $"/source/{file.LastWriteTime:yyyy-MM-dd}";
            var archiveDirectory= _newPath + "/archive";
            var newFilePath= Path.Combine(clientDirectory, $"{Path.GetFileNameWithoutExtension(file.Name)}_{file.CreationTime:yyyy_MM_dd_hh-mm-ss}");
            var newArchivePath= Path.Combine(archiveDirectory, $"{Path.GetFileNameWithoutExtension(file.Name)}_{file.CreationTime:yyyy_MM_dd_hh-mm-ss}");
            
            CreateUniquePath(ref newFilePath);
            CreateUniquePath(ref newArchivePath);
            
            newFilePath += ".gz";
            newArchivePath += ".gz";
            
            AwaitForTheFileToClose(file.FullName);
            File.WriteAllText(file.FullName, Encryption.Encrypt(File.ReadAllText(file.FullName), key));
            Directory.CreateDirectory(clientDirectory);
            Logger.CreateDirectory(clientDirectory);
            Directory.CreateDirectory(archiveDirectory);
            Logger.CreateDirectory(archiveDirectory);
            Archive.Compress(file.FullName, newFilePath);
            Archive.Compress(file.FullName, newArchivePath);
            Archive.Decompress(newFilePath, Path.ChangeExtension(newFilePath, "txt"));
            File.Delete(newFilePath);
            
            newFilePath = Path.ChangeExtension(newFilePath, "txt");
            var text = Encryption.Decrypt(File.ReadAllText(newFilePath), key);
            File.WriteAllText(newFilePath, text);
        }
        
        private static void CreateUniquePath(ref string path)
        {
            var buff = path;
            for(var i = 1; File.Exists(path); i++)
            {
                buff = path + $"({i})";
                Console.WriteLine(buff);
            }
            path = buff;
        }
        
        private static void AwaitForTheFileToClose(string path)
        {
            while (true)
            {
                try
                {
                    using var stream = new FileStream(path, FileMode.Open);
                    return;
                }
                catch
                {
                    Console.WriteLine("Error!");
                }
            }
        }
    }
}