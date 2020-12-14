using System.IO.Compression;

namespace ETL.ConfigManager.Models
{
    public class ArchiveOptions : Options
    {
        public CompressionLevel CompressionLevel { get; set; } = CompressionLevel.Optimal;
    }
}