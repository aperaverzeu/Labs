using System;
using System.IO;
using System.Linq;
using ETL.ConfigManager.Models;

namespace ETL.ServiceManager
{
    public class Logger
    {
        private readonly LoggingOptions _options;
        
        public Logger(LoggingOptions options)
        {
            _options = options;
            try
            {
                var name = options.LogPath.Split('/').Last();
                var path = options.LogPath.Substring(0, options.LogPath.Length - name.Length);
                if(!Directory.Exists(path))
                {
                    Directory.CreateDirectory(path);
                }
                if(!File.Exists(options.LogPath))
                {
                    File.Create(options.LogPath).Close();
                }
            }
            catch
            {
                options.EnableLogging = false;
            }
        }
        
        public void Log(string message)
        {
            if (_options.EnableLogging)
            {
                using var log = new StreamWriter(_options.LogPath, true);
                log.WriteLine($"[{DateTime.Now:hh:mm:ss dd.MM.yyyy}] - {message}");
            }
        }
    }
}