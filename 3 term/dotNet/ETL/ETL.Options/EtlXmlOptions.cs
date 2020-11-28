namespace ETL.Options
{
    public class EtlXmlOptions : EtlOptions
    {
        public EtlXmlOptions(string xml) : base()
        {
            var options = Converter.DeserializeXml<EtlOptions>(xml);
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