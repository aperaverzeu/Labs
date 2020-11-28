namespace ETL.Options
{
    public class LoggingOptions : Options
    {
        public bool EnableLogging { get; set; } = true;
        public string LogPath { get; set; } = "ETL/Log/log.txt";
    }
}