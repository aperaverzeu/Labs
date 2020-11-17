using System;
using System.IO;
using System.Security.Cryptography;

namespace ETLibrary
{
    public static class Encryption
    {
        public static byte[] GenerateKey(int length)
        {
            var array = new byte[length];
            var random = new Random();
            for(var i = 0; i < length; i++)
            {
                array[i] = (byte)random.Next(0, 256);
            }
            return array;
        }

        public static string Encrypt(object obj, byte[] key)
        {
            using (var aes = Aes.Create())
            {
                var cryptoTransform = aes?.CreateEncryptor(key, new byte[16]);
                using (var stream = new MemoryStream())
                {
                    using (var cryptoStream = new CryptoStream(stream, cryptoTransform, CryptoStreamMode.Write))
                    {
                        using (var streamWriter = new StreamWriter(cryptoStream))
                        {
                            streamWriter.Write(obj);
                        }
                        var res =  Convert.ToBase64String(stream.ToArray());
                        return res;
                    }
                }
            }
        }

        public static string Decrypt(string input, byte[] key)
        {
            using (var aes = Aes.Create())
            {
                var cryptoTransform = aes?.CreateDecryptor(key, new byte[16]);
                using (var stream = new MemoryStream(Convert.FromBase64String(input)))
                {
                    using (var cryptoStream = new CryptoStream(stream, cryptoTransform, CryptoStreamMode.Read))
                    {
                        string output;
                        using (var streamReader = new StreamReader(cryptoStream))
                        {
                            output = streamReader.ReadToEnd();
                        }
                        return output;
                    }
                }
            }
        }
    }
}
