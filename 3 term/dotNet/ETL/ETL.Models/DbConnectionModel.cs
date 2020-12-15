using System.ComponentModel.DataAnnotations;

namespace ETL.Models
{
    public class DbConnectionModel
    {
        [Key] 
        public int Id { get; set; }
        public string DataSource { get; set; }
        public string UserID { get; set; }
        public string Password { get; set; }
        public string InitialCatalog { get; set; }
    }
}