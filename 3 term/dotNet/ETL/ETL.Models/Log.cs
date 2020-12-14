using System.ComponentModel.DataAnnotations;

namespace ETL.Models
{
    public class Log
    {
        [Key] 
        public int Id { get; set; }
        public string Time { get; set; }
        public string Message { get; set; }
    }
}