namespace ETL.ConfigManager.Models
{
    public class LoggingOptions : Options
    {
        public bool EnableLogging { get; set; } = true;
        public string LogPath { get; set; } = "ETL/Logs/log.txt";
    }
}