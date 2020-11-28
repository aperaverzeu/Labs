namespace ETL.Options
{
    public class MoveOptions : Options
    {
        public string SourceDirectory { get; set; } = "/Users/alex/Desktop/folder/source";
        public string TargetDirectory { get; set; } = "/Users/alex/Desktop/folder/target";
        public string ArchiveDirectory { get; set; } = "/Users/alex/Desktop/folder/target/archive";
        public string TargetSourceDirectory { get; set; } = "/Users/alex/Desktop/folder/target/source";
    }
}