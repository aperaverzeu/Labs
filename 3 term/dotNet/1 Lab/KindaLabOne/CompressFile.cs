using System;
using System.IO;
using System.IO.Compression;

namespace KindaLabOne
{
    public class CompressFile : ICommand
    {
        private readonly string _path;
        private readonly string _compressedPath;

        public CompressFile(string path, string compressedPath)
        {
            _path = path;
            _compressedPath = compressedPath;
        }


        public void Execute()
        {
            try
            {
                using var sourceStream = new FileStream(_path, FileMode.OpenOrCreate);
                using var targetStream = File.Create(_compressedPath);
                using var compressionStream = new GZipStream(targetStream, CompressionMode.Compress);
                sourceStream.CopyTo(compressionStream);
                Console.WriteLine("Compression file {0} is passed good. Size before: {1}  size after: {2}.",
                    _path, sourceStream.Length.ToString(), targetStream.Length.ToString());
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
                throw;
            }
        }
    }
}