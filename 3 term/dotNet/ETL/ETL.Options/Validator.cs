using System.IO;
using System.Linq;

namespace ETL.Options
{
    public class Validator
    {
        public static string Validate(EtlOptions options)
        {
            var report = "";
            #region Sending Validation
            var moving = options.MoveOptions;
            if(!CreateDirectoryIfNotExist(moving.SourceDirectory))
            {
                moving.SourceDirectory = "/Users/alex/Desktop/folder/source";
                CreateDirectoryIfNotExist(moving.SourceDirectory);
                report += "Cannot open source directory, using default. ";
            }
            if(!CreateDirectoryIfNotExist(moving.TargetDirectory))
            {
                moving.TargetDirectory = "/Users/alex/Desktop/folder/target";
                report += "Cannot open target directory, using default. ";
                CreateDirectoryIfNotExist(moving.TargetDirectory);
            }
            if(!CreateDirectoryIfNotExist(moving.ArchiveDirectory))
            {
                moving.ArchiveDirectory = "/Users/alex/Desktop/folder/target/archive";
                report += "Cannot open target archive, using default. ";
                CreateDirectoryIfNotExist(moving.ArchiveDirectory);
            }
            if (!CreateDirectoryIfNotExist(moving.TargetSourceDirectory))
            {
                moving.TargetSourceDirectory = "/Users/alex/Desktop/folder/target/source";
                report += "Cannot open target source, using default. ";
            }
            #endregion
            #region Logging Validation
            var logging = options.LoggingOptions;
            if(!CreateFileIfNotExist(logging.LogPath))
            {
                logging.LogPath = "/Users/alex/Desktop/folder/target/log.txt";
                report += "Cannot open source log file, using default. ";
                CreateFileIfNotExist(logging.LogPath);
            }
            #endregion
            #region Encryption Validation
            var encryption = options.EncryptionOptions;
            if(!encryption.RandomKey && encryption.Key.Length != 16)
            {
                report += "Encryption key's length must be 16, using random key. ";
            }
            #endregion
            #region Archive Validation
            var archive = options.ArchiveOptions;
            // ReSharper disable once InvertIf
            if((int)archive.CompressionLevel < 0 || (int)archive.CompressionLevel > 2)
            {
                archive.CompressionLevel = System.IO.Compression.CompressionLevel.Optimal;
                report += "Compression level value can't be below zero and above 2, using default value. ";
            }
            #endregion
            return report;
        }
        
        public static bool CreateDirectoryIfNotExist(string path)
        {
            try
            {
                if(!Directory.Exists(path))
                {
                    Directory.CreateDirectory(path);
                }
                return true;
            }
            catch
            {
                return false;
            }
        }
        
        private static bool CreateFileIfNotExist(string path)
        {
            try
            {
                var name = path.Trim('/').Split('/').Last();
                var p = path.Substring(0, path.Length - name.Length);
                if(!Directory.Exists(p))
                {
                    Directory.CreateDirectory(p);
                }
                if(!File.Exists(path))
                {
                    File.Create(path).Close();
                }
                return true;
            }
            catch
            {
                return false;
            }
        }
    }
}