using System;
using System.Data.SqlClient;
using System.Globalization;
using System.IO;
using ETL.Db;

namespace ETL.Library
{
    public class Move
    {
        private readonly string _source;
        private static string _target;
        private FileSystemWatcher _watcher;
        private static readonly Logger Logger = new Logger("/Users/alex/Desktop/folder/target/logWithoutDb.txt", true);
        private static readonly SqlConnectionStringBuilder Builder = new SqlConnectionStringBuilder
        {
            DataSource = "localhost",
            UserID = "sa",
            Password = "StrongAdminPa55word",
            InitialCatalog = "EFSampleDB3"
        };
        private static readonly NoteContext Context = new NoteContext(Builder.ConnectionString);
        private static readonly MoveDb MoveDb = new MoveDb(Context);

        public Move(string source, string target)
        {
            _source = source;
            _target = target;
        }
        
        public void Run()
        {
            

            _watcher = new FileSystemWatcher(_source)
            {
                Filter = "*.txt",
                EnableRaisingEvents = true,
                IncludeSubdirectories = true
            };
            _watcher.Created += OnCreated;
            
            Console.WriteLine("Run!");
            Logger.Log("Run application\t");
            Console.WriteLine("Press any key to finish...");
            Console.ReadKey(true);
            Logger.Log("Stop application\n");
        }

        private static void OnCreated(object sender, FileSystemEventArgs e)
        {
            var file = new FileInfo(e.FullPath);
            var key = Encryption.GenerateKey(16);
            var clientDirectory = _target +  $"/source/{file.LastWriteTime:yyyy-MM-dd}";
            var archiveDirectory= _target + "/archive";
            var newFilePath= Path.Combine(clientDirectory, $"{Path.GetFileNameWithoutExtension(file.Name)}_{file.CreationTime:yyyy_MM_dd_hh-mm-ss}");
            var newArchivePath= Path.Combine(archiveDirectory, $"{Path.GetFileNameWithoutExtension(file.Name)}_{file.CreationTime:yyyy_MM_dd_hh-mm-ss}");
            
            CreateUniquePath(ref newFilePath);
            CreateUniquePath(ref newArchivePath);
            
            newFilePath += ".gz";
            newArchivePath += ".gz";
            
            using (new FileStream(file.FullName, FileMode.Open)) {}
            File.WriteAllText(file.FullName, Encryption.Encrypt(File.ReadAllText(file.FullName), key));
            Logger.Log("File encrypted!");
            Directory.CreateDirectory(clientDirectory);
            Directory.CreateDirectory(archiveDirectory);
            Archive.Compress(file.FullName, newFilePath);
            Archive.Compress(file.FullName, newArchivePath);
            Logger.Log("File compressed!");
            Archive.Decompress(newFilePath, Path.ChangeExtension(newFilePath, "txt"));
            File.Delete(newFilePath);
            
            newFilePath = Path.ChangeExtension(newFilePath, "txt");
            var text = Encryption.Decrypt(File.ReadAllText(newFilePath), key);
            Logger.Log("File decrypted!");
            File.WriteAllText(newFilePath, text);
            Logger.Log("File goes right!");
            try
            { 
                MoveDb.CreateNote(MoveDb.GenerateId(), file.CreationTime.ToString(CultureInfo.InvariantCulture), text);
            }
            catch (Exception exception)
            {
                Logger.Log("Unable to create Note in Db -– " + exception.Message);
            }
            
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
    }
}