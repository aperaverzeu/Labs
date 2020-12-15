using System.ComponentModel.DataAnnotations;

namespace ETL.Models
{
    public class ArchiveModel
    {
        [Key] 
        public int Id { get; set; }
        public string CompressionLevel { get; set; }
    }
}