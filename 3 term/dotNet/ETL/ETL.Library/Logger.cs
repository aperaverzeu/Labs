using System;
using System.IO;
using System.Linq;
using ETL.Options;

namespace ETL.Library
{
    public class Logger
    {
        private readonly LoggingOptions _options;
        
        public Logger(LoggingOptions options)
        {
            _options = options;
            try
            {
                var name = _options.LogPath.Split('/').Last();
                var path = _options.LogPath.Substring(0, options.LogPath.Length - name.Length);
                if(!Directory.Exists(path))
                {
                    Directory.CreateDirectory(path);
                }
                if(!File.Exists(_options.LogPath))
                {
                    File.Create(_options.LogPath).Close();
                }
            }
            catch
            {
                _options.EnableLogging = false;
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