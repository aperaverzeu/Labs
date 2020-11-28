namespace ETL.Options
{
    public class EtlJsonOptions : EtlOptions
    {
        public EtlJsonOptions(string json) : base()
        {
            var options = Converter.DeserializeJson<EtlOptions>(json);
            ArchiveOptions = options.ArchiveOptions;
            EncryptionOptions = options.EncryptionOptions;
            LoggingOptions = options.LoggingOptions;
            MoveOptions = options.MoveOptions;
            MoveDbOptions = options.MoveDbOptions;
            WatcherOptions = options.WatcherOptions;
            Report = Validator.Validate(this);
        }
    }
}