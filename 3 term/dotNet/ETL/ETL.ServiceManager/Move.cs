using System;
using System.Data.SqlClient;
using System.Globalization;
using System.IO;
using ETL.ConfigManager;
using ETL.ConfigManager.EtlOptions;
using ETL.DataAccess;
using ETL.DataManager;
using ETL.FileManager;

namespace ETL.ServiceManager
{
    public class Move
    {
        private FileSystemWatcher _watcher;
        private static Logger _logger;
        private static OptionManager _optionManager;
        private static readonly SqlConnectionStringBuilder Builder = new SqlConnectionStringBuilder();
        private static readonly NoteContext NoteContext = new NoteContext(Builder.ConnectionString);
        private static readonly LogContext LogContext = new LogContext(Builder.ConnectionString);
        private static readonly MoveDb MoveDb = new MoveDb(NoteContext, LogContext);

        public void Run()
        {
            Configuration();
            
            Console.WriteLine("Run!");
            _logger.Log("Run application\t");
            MoveDb.CreateLog(MoveDb.GenerateLogId(), $"{DateTime.Now:hh:mm:ss dd.MM.yyyy}", "Run application");
            Console.WriteLine("Press any key to finish...");
            Console.ReadKey(true);
            _logger.Log("Stop application\n\n");
        }

        private void Configuration()
        {
            const string configs = "ETL/Configs";
            _optionManager = new OptionManager(configs);
            var options = _optionManager.GetOptions<EtlOptions>() as EtlOptions;
            if (options == null)
            {
                _logger.Log("Options is null!");
                return;
            }
            
            _logger = new Logger(options.LoggingOptions);
            _logger.Log(_optionManager.Report);
            
            try
            {
                _watcher = new FileSystemWatcher(options.MoveOptions.SourceDirectory)
                {
                    Filter = options.WatcherOptions.Filter,
                    EnableRaisingEvents = options.WatcherOptions.EnableRaisingEvents,
                    IncludeSubdirectories = options.WatcherOptions.IncludeSubdirectories
                };
                _watcher.Created += OnCreated;
            }
            catch (Exception e)
            {
                _logger.Log("Watcher goes wrong! -- " + e.Message);
            }
            try
            {
                Builder.DataSource = options.MoveDbOptions.DataSource;
                Builder.UserID = options.MoveDbOptions.UserID;
                Builder.Password = options.MoveDbOptions.Password;
                Builder.InitialCatalog = options.MoveDbOptions.InitialCatalog;
            }
            catch(Exception e)
            {
                _logger.Log("Cannot access connection string -- " + e.Message);
                return;
            }
            try
            {
                if (NoteContext._connectionString == "" || LogContext._connectionString == "")
                {
                    NoteContext._connectionString = Builder.ConnectionString;
                    LogContext._connectionString = Builder.ConnectionString;
                }
            }
            catch (Exception e)
            {
                var mess = "Something goes wrong with connection string -- " + e.Message;
                _logger.Log(mess);
                MoveDb.CreateLog(MoveDb.GenerateLogId(), $"{DateTime.Now:hh:mm:ss dd.MM.yyyy}", mess);
            }
        }

        private static void OnCreated(object sender, FileSystemEventArgs e)
        {
            var file = new FileInfo(e.FullPath);
            var options = _optionManager.GetOptions<EtlOptions>() as EtlOptions;
            MovingFile(file, options);
        }

        private static void MovingFile(FileSystemInfo file, EtlOptions options)
        {
            byte[] key = {};
            string clientDirectory = "", 
                archiveDirectory = "", 
                newFilePath = "", 
                newArchivePath = "";
            try
            {
                key = Encryption.GenerateKey(16);
                _logger.Log(key == null ? "Key is null!" : "Key generated");
            }
            catch (Exception e)
            {
                _logger.Log("Troubles with generating key -- " + e.Message);
            }
            try
            {
                clientDirectory = options.MoveOptions.TargetDirectory + $"/source/{file.LastWriteTime:yyyy-MM-dd}";
                _logger.Log("Created client directory");
            }
            catch (Exception e)
            {
                _logger.Log("Cannot create client directory -- " + e.Message);
            }
            try
            {
                archiveDirectory = options.MoveOptions.ArchiveDirectory;
                _logger.Log("Created archive directory");
            }
            catch (Exception e)
            {
                _logger.Log("Cannot create archive directory -- " + e.Message);
            }
            try
            {
                newFilePath = Path.Combine(clientDirectory, $"{Path.GetFileNameWithoutExtension(file.Name)}_{file.CreationTime:yyyy_MM_dd_hh-mm-ss}");
                _logger.Log("Create new file path");
            }
            catch (Exception e)
            {
                _logger.Log("Unable to create new path for file -- " + e.Message);
            }
            try
            {
                newArchivePath= Path.Combine(archiveDirectory, $"{Path.GetFileNameWithoutExtension(file.Name)}_{file.CreationTime:yyyy_MM_dd_hh-mm-ss}");
                _logger.Log("Create new file path for archive");
            }
            catch (Exception e)
            {
                _logger.Log("Unable to create new archive path for file -- " + e.Message);
            }
            
            CreateUniquePath(ref newFilePath);
            CreateUniquePath(ref newArchivePath);
            
            newFilePath += ".gz";
            newArchivePath += ".gz";
            
            using (new FileStream(file.FullName, FileMode.Open)) {}

            try
            {
                File.WriteAllText(file.FullName, Encryption.Encrypt(File.ReadAllText(file.FullName), key));
                _logger.Log($"File {file.Name} encrypted");
            }
            catch (Exception e)
            {
                _logger.Log("Encryption failed  -- " + e.Message);
            }
            try
            {
                Directory.CreateDirectory(clientDirectory);
                _logger.Log("Client directory created");
            }
            catch (Exception e)
            {
                _logger.Log("Client directory cannot create -- " + e.Message);
            }
            try
            {
                Directory.CreateDirectory(archiveDirectory);
                _logger.Log("Archive directory created");
            }
            catch (Exception e)
            {
                _logger.Log("Archive directory cannot create -- " + e.Message);
            }
            try
            {
                Archive.Compress(file.FullName, newFilePath, options.ArchiveOptions.CompressionLevel);
                _logger.Log($"File {file.Name} compressed");
            }
            catch (Exception e)
            {
                _logger.Log($"Unable to compress file {file.FullName} -- " + e.Message);
            }
            try
            {
                Archive.Compress(file.FullName, newArchivePath, options.ArchiveOptions.CompressionLevel);
                _logger.Log($"File {file.Name} compressed to archive");
            }
            catch (Exception e)
            {
                _logger.Log($"Unable to compress file {file.FullName} -- " + e.Message);
            }
            try
            {
                Archive.Decompress(newFilePath, Path.ChangeExtension(newFilePath, "txt"));
                _logger.Log($"File {file.Name} decompressed");
            }
            catch (Exception e)
            {
                _logger.Log($"Unable to decompress file {file.FullName} -- " + e.Message);
            }
            File.Delete(newFilePath);
            
            newFilePath = Path.ChangeExtension(newFilePath, "txt");
            var text = "";
            try
            {
                text = Encryption.Decrypt(File.ReadAllText(newFilePath), key);
                _logger.Log($"File {file.Name} encrypted!");
            }
            catch (Exception e)
            {
                _logger.Log($"Cannot decrypt file {file.FullName} -- " + e.Message);
            }
            try
            {
                File.WriteAllText(newFilePath, text);
                _logger.Log("File written");
            }
            catch (Exception e)
            {
                _logger.Log("File cannot be written -- " + e.Message);
            }
            try
            { 
                MoveDb.CreateNote(MoveDb.GenerateId(), file.CreationTime.ToString(CultureInfo.InvariantCulture), text);
                _logger.Log($"Create Note in Db from {file.Name}");
            }
            catch (Exception exception)
            {
                _logger.Log("Unable to create Note in Db -– " + exception.Message);
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