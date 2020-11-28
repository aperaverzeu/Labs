namespace ETL.Options
{
    public class WatcherOptions : Options
    {
        public string Filter { get; set; } = "*.txt";
        public bool EnableRaisingEvents { get; set; } = true;
        public bool IncludeSubdirectories { get; set; } = true;
    }
}