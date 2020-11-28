using System;
using System.IO;
using System.Linq;

namespace ETL.Library
{
    public class Logger
    {
        private readonly bool _enableLogging;
        private readonly string _logPath;
        
        public Logger(string logPath, bool enableLogging)
        {
            _logPath = logPath;
            _enableLogging = enableLogging;
            try
            {
                var name = _logPath.Split('/').Last();
                var path = _logPath.Substring(0, logPath.Length - name.Length);
                if(!Directory.Exists(path))
                {
                    Directory.CreateDirectory(path);
                }
                if(!File.Exists(_logPath))
                {
                    File.Create(_logPath).Close();
                }
            }
            catch
            {
                _enableLogging = false;
            }
        }
        
        public void Log(string message)
        {
            if (_enableLogging)
            {
                using var log = new StreamWriter(_logPath, true);
                log.WriteLine($"[{DateTime.Now:hh:mm:ss dd.MM.yyyy}] - {message}");
            }
        }
    }
}