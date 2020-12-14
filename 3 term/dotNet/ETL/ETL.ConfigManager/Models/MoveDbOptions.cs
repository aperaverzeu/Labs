namespace ETL.ConfigManager.Models
{
    public class MoveDbOptions : Options
    {
        public string DataSource { get; set; } = "localhost";
        public string UserID { get; set; } = "sa";
        public string Password { get; set; } = "StrongAdminPa55word";
        public string InitialCatalog { get; set; } = "EFSampleDB3";
    }
}