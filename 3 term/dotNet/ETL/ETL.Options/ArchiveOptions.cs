using System.IO.Compression;

namespace ETL.Options
{
    public class ArchiveOptions : Options
    {
        public CompressionLevel CompressionLevel { get; set; } = CompressionLevel.Optimal;
    }
}