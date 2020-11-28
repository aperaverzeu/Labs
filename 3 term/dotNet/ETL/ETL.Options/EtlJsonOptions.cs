namespace ETL.Options
{
    public class EtlJsonOptions : EtlOptions
    { 
        EtlJsonOptions(string json) : base()
        {
            // ToDo options = Deserialize Json
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