namespace ETL.Options
{
    public class EtlOptions : Options
    {
        public ArchiveOptions ArchiveOptions { get; set; } = new ArchiveOptions();
        public EncryptionOptions EncryptionOptions { get; set; } = new EncryptionOptions();
        public LoggingOptions LoggingOptions { get; set; } = new LoggingOptions();
        public MoveOptions MoveOptions { get; set; } = new MoveOptions();
        public MoveDbOptions MoveDbOptions { get; set; } = new MoveDbOptions();
        public WatcherOptions WatcherOptions { get; set; } = new WatcherOptions();

        public string Report { get; protected set; } = "";

        public EtlOptions() {}

        public EtlOptions(ArchiveOptions archiveOptions, EncryptionOptions encryptionOptions, LoggingOptions loggingOptions, MoveOptions moveOptions, MoveDbOptions moveDbOptions, WatcherOptions watcherOptions)
        {
            ArchiveOptions = archiveOptions;
            EncryptionOptions = encryptionOptions;
            LoggingOptions = loggingOptions;
            MoveOptions = moveOptions;
            MoveDbOptions = moveDbOptions;
            WatcherOptions = watcherOptions;
        }
    }
}