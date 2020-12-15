using System.ComponentModel.DataAnnotations;

namespace ETL.Models
{
    public class WatcherModel
    {
        [Key] 
        public int Id { get; set; }
        public string Filter { get; set; }
        public string EnableRaisingEvents { get; set; }
        public string IncludeSubdirectories { get; set; }
    }
}