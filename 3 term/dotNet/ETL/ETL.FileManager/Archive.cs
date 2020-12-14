using System.IO;
using System.IO.Compression;

namespace ETL.FileManager
{
    public static class Archive
    {
        public static void Compress(string source, string target, CompressionLevel level)
        {
            using var sourceStream = new FileStream(source, FileMode.Open);
            using var targetStream = File.Create(target);
            using var zipStream = new GZipStream(targetStream, level);
            sourceStream.CopyTo(zipStream);
        }
        
        public static void Decompress(string source, string target)
        {
            using var sourceStream = new FileStream(source, FileMode.OpenOrCreate);
            using var targetStream = File.Create(target);
            using var zipStream = new GZipStream(sourceStream, CompressionMode.Decompress);
            zipStream.CopyTo(targetStream);
        }
    }
}