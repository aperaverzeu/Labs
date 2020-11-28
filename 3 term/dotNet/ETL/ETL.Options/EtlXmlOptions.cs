namespace ETL.Options
{
    public class EtlXmlOptions : EtlOptions
    {
        EtlXmlOptions(string xml) : base()
        {
            // ToDo options = Deserialize Xml
            ArchiveOptions = options.ArchiveOptions;
            EncryptionOptions = options.EncryptionOptions;
            LoggingOptions = options.LoggingOptions;
            MoveOptions = options.MoveOptions;
            MoveDbOptions = options.MoveDbOptions;
            WatcherOptions = options.WatcherOptions;
            // ToDo create Validator
            // Report = Validator.Validate(this);
        }
    }
}