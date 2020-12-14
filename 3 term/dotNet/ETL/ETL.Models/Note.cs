using System.ComponentModel.DataAnnotations;

namespace ETL.Models
{
    public class Note
    {
        [Key]
        public int Id { get; set; }
        public string CreationDate { get; set; }
        public string Content { get; set; }
    }
}