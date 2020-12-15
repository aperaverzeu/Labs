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
        private static readonly ArchiveOptionContext ArchiveOptionContext = new ArchiveOptionContext(Builder.ConnectionString);
        private static readonly DbConnectionOptionContext DbConnectionOptionContext = new DbConnectionOptionContext(Builder.ConnectionString);
        private static readonly WatcherOptionContext WatcherOptionContext = new WatcherOptionContext(Builder.ConnectionString);
        private static readonly MoveDb MoverToDb = new MoveDb(NoteContext);
        private static readonly MoveLogDb MoverLogsToDb = new MoveLogDb(LogContext);
        private static readonly MoveOptionsDb MoverOptionsToDb = new MoveOptionsDb(ArchiveOptionContext, DbConnectionOptionContext, WatcherOptionContext);

        public void Run()
        {
            Configuration();
            
            Console.WriteLine("Run!");
            _logger.Log("Run application\t");
            MoverLogsToDb.CreateLog(MoverLogsToDb.GenerateId(), $"{DateTime.Now:hh:mm:ss dd.MM.yyyy}", "Run application");
            Console.WriteLine("Press any key to finish...");
            Console.ReadKey(true);
            _logger.Log("Stop application\n\n");
            MoverLogsToDb.CreateLog(MoverLogsToDb.GenerateId(), $"{DateTime.Now:hh:mm:ss dd.MM.yyyy}", "Stop application");
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
                Builder.DataSource = options.MoveDbOptions.DataSource;
                Builder.UserID = options.MoveDbOptions.UserID;
                Builder.Password = options.MoveDbOptions.Password;
                Builder.InitialCatalog = options.MoveDbOptions.InitialCatalog;
            }
            catch(Exception e)
            {
                var mess = "Cannot access connection string -- " + e.Message;
                _logger.Log(mess);
                return;
            }
            try
            {
                if (NoteContext._connectionString == "" || LogContext._connectionString == "" || ArchiveOptionContext._connectionString == "" || DbConnectionOptionContext._connectionString == "" || WatcherOptionContext._connectionString == "")
                {
                    NoteContext._connectionString = Builder.ConnectionString; 
                    LogContext._connectionString = Builder.ConnectionString;
                    ArchiveOptionContext._connectionString = Builder.ConnectionString;
                    DbConnectionOptionContext._connectionString = Builder.ConnectionString;
                    WatcherOptionContext._connectionString = Builder.ConnectionString;
                }
            }
            catch (Exception e)
            {
                var mess = "Something goes wrong with connection string -- " + e.Message;
                _logger.Log(mess);
                MoverLogsToDb.CreateLog(MoverLogsToDb.GenerateId(), $"{DateTime.Now:hh:mm:ss dd.MM.yyyy}", mess);
            }
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
                var mess = "Watcher goes wrong! -- " + e.Message;
                _logger.Log(mess);
            }
            try
            {
                MoverOptionsToDb.CreateConnectionOption(MoverOptionsToDb.GenerateConnectionId(), 
                    options.MoveDbOptions.DataSource,
                    options.MoveDbOptions.UserID,
                    options.MoveDbOptions.Password,
                    options.MoveDbOptions.InitialCatalog);
            }
            catch (Exception e)
            {
                var mess = "Cannot access an options database! -- " + e.Message;
                _logger.Log(mess);
            }
            try
            {
                MoverOptionsToDb.CreateWatcherOption(MoverOptionsToDb.GenerateWatcherId(), 
                    options.WatcherOptions.Filter, 
                    options.WatcherOptions.IncludeSubdirectories.ToString(), 
                    options.WatcherOptions.EnableRaisingEvents.ToString());
            }
            catch (Exception e)
            {
                var mess = "Cannot access an options database! -- " + e.Message;
                _logger.Log(mess);
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
                var mess = "Troubles with generating key -- " + e.Message;
                _logger.Log(mess);
                MoverLogsToDb.CreateLog(MoverLogsToDb.GenerateId(), $"{DateTime.Now:hh:mm:ss dd.MM.yyyy}", mess);
            }
            try
            {
                clientDirectory = options.MoveOptions.TargetDirectory + $"/source/{file.LastWriteTime:yyyy-MM-dd}";
                _logger.Log("Created client directory");
            }
            catch (Exception e)
            {
                var mess = "Cannot create client directory -- " + e.Message;
                _logger.Log(mess);
                MoverLogsToDb.CreateLog(MoverLogsToDb.GenerateId(), $"{DateTime.Now:hh:mm:ss dd.MM.yyyy}", mess);
            }
            try
            {
                archiveDirectory = options.MoveOptions.ArchiveDirectory;
                _logger.Log("Created archive directory");
            }
            catch (Exception e)
            {
                var mess = "Cannot create archive directory -- " + e.Message;
                _logger.Log(mess);
                MoverLogsToDb.CreateLog(MoverLogsToDb.GenerateId(), $"{DateTime.Now:hh:mm:ss dd.MM.yyyy}", mess);
            }
            try
            {
                newFilePath = Path.Combine(clientDirectory, $"{Path.GetFileNameWithoutExtension(file.Name)}_{file.CreationTime:yyyy_MM_dd_hh-mm-ss}");
                _logger.Log("Create new file path");
            }
            catch (Exception e)
            {
                var mess = "Unable to create new path for file -- " + e.Message;
                _logger.Log(mess);
                MoverLogsToDb.CreateLog(MoverLogsToDb.GenerateId(), $"{DateTime.Now:hh:mm:ss dd.MM.yyyy}", mess);
            }
            try
            {
                newArchivePath= Path.Combine(archiveDirectory, $"{Path.GetFileNameWithoutExtension(file.Name)}_{file.CreationTime:yyyy_MM_dd_hh-mm-ss}");
                _logger.Log("Create new file path for archive");
            }
            catch (Exception e)
            {
                var mess = "Unable to create new archive path for file -- " + e.Message;
                _logger.Log(mess);
                MoverLogsToDb.CreateLog(MoverLogsToDb.GenerateId(), $"{DateTime.Now:hh:mm:ss dd.MM.yyyy}", mess);
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
                var mess = "Encryption failed  -- " + e.Message;
                _logger.Log(mess);
                MoverLogsToDb.CreateLog(MoverLogsToDb.GenerateId(), $"{DateTime.Now:hh:mm:ss dd.MM.yyyy}", mess);
            }
            try
            {
                Directory.CreateDirectory(clientDirectory);
                _logger.Log("Client directory created");
            }
            catch (Exception e)
            {
                var mess = "Client directory cannot create -- " + e.Message;
                _logger.Log(mess);
                MoverLogsToDb.CreateLog(MoverLogsToDb.GenerateId(), $"{DateTime.Now:hh:mm:ss dd.MM.yyyy}", mess);
            }
            try
            {
                Directory.CreateDirectory(archiveDirectory);
                _logger.Log("Archive directory created");
            }
            catch (Exception e)
            {
                var mess = "Archive directory cannot create -- " + e.Message;
                _logger.Log(mess);
                MoverLogsToDb.CreateLog(MoverLogsToDb.GenerateId(), $"{DateTime.Now:hh:mm:ss dd.MM.yyyy}", mess);
            }
            try
            {
                Archive.Compress(file.FullName, newFilePath, options.ArchiveOptions.CompressionLevel);
                _logger.Log($"File {file.Name} compressed");
                
                MoverOptionsToDb.CreateArchiveOption(MoverOptionsToDb.GenerateArchiveId(), options.ArchiveOptions.CompressionLevel.ToString());
            }
            catch (Exception e)
            {
                var mess = $"Unable to compress file {file.FullName} -- " + e.Message;
                _logger.Log(mess);
                MoverLogsToDb.CreateLog(MoverLogsToDb.GenerateId(), $"{DateTime.Now:hh:mm:ss dd.MM.yyyy}", mess);
            }
            try
            {
                Archive.Compress(file.FullName, newArchivePath, options.ArchiveOptions.CompressionLevel);
                _logger.Log($"File {file.Name} compressed to archive");
            }
            catch (Exception e)
            {
                var mess = $"Unable to compress file {file.FullName} -- " + e.Message;
                _logger.Log(mess);
                MoverLogsToDb.CreateLog(MoverLogsToDb.GenerateId(), $"{DateTime.Now:hh:mm:ss dd.MM.yyyy}", mess);
            }
            try
            {
                Archive.Decompress(newFilePath, Path.ChangeExtension(newFilePath, "txt"));
                _logger.Log($"File {file.Name} decompressed");
            }
            catch (Exception e)
            {
                var mess = $"Unable to decompress file {file.FullName} -- " + e.Message;
                _logger.Log(mess);
                MoverLogsToDb.CreateLog(MoverLogsToDb.GenerateId(), $"{DateTime.Now:hh:mm:ss dd.MM.yyyy}", mess);
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
                var mess = $"Cannot decrypt file {file.FullName} -- " + e.Message;
                _logger.Log(mess);
                MoverLogsToDb.CreateLog(MoverLogsToDb.GenerateId(), $"{DateTime.Now:hh:mm:ss dd.MM.yyyy}", mess);
            }
            try
            {
                File.WriteAllText(newFilePath, text);
                _logger.Log("File written");
            }
            catch (Exception e)
            {
                var mess = "File cannot be written -- " + e.Message;
                _logger.Log(mess);
                MoverLogsToDb.CreateLog(MoverLogsToDb.GenerateId(), $"{DateTime.Now:hh:mm:ss dd.MM.yyyy}", mess);
            }
            try
            { 
                MoverToDb.CreateNote(MoverToDb.GenerateId(), file.CreationTime.ToString(CultureInfo.InvariantCulture), text);
                _logger.Log($"Create Note in Db from {file.Name}");
            }
            catch (Exception exception)
            {
                var mess = "Unable to create Note in Db -– " + exception.Message;
                _logger.Log(mess);
                MoverLogsToDb.CreateLog(MoverLogsToDb.GenerateId(), $"{DateTime.Now:hh:mm:ss dd.MM.yyyy}", mess);
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