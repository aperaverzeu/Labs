using ETL.Models;
using Microsoft.EntityFrameworkCore;

namespace ETL.DataAccess
{
    public class ArchiveOptionContext : DbContext
    {
        public DbSet<ArchiveModel> ArchiveOptions { get; set; }

        public string _connectionString;

        public ArchiveOptionContext(string connectionString)
        {
            _connectionString = connectionString;
        }
        
        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            optionsBuilder.UseSqlServer(_connectionString);
        }
    }
}