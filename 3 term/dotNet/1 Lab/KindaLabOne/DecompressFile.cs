using System;
using System.IO;
using System.IO.Compression;

namespace KindaLabOne
{
    public class DecompressFile : ICommand
    {
        private readonly string _compressedPath;
        private readonly string _targetPath;

        public DecompressFile(string compressedPath, string targetPath)
        {
            _compressedPath = compressedPath;
            _targetPath = targetPath;
        }

        public void Execute()
        {
            try
            {
                using var sourceStream = new FileStream(_compressedPath, FileMode.OpenOrCreate);
                using var targetStream = File.Create(_targetPath);
                using var decompressionStream = new GZipStream(sourceStream, CompressionMode.Decompress);
                decompressionStream.CopyTo(targetStream);
                Console.WriteLine("Restored file: {0}", _targetPath);
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
                throw;
            }
        }
    }
}