namespace ETL.Options
{
    public class EncryptionOptions : Options
    {
        public bool EnableEncryption { get; set; } = true;
        public bool RandomKey { get; set; } = true;
        public byte[] Key { get; set; } = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
    }
}