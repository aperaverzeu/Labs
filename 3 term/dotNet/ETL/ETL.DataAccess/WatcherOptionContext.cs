using ETL.Models;
using Microsoft.EntityFrameworkCore;

namespace ETL.DataAccess
{
    public class WatcherOptionContext : DbContext
    {
        public DbSet<WatcherModel> WatcherOptions { get; set; }

        public string _connectionString;

        public WatcherOptionContext(string connectionString)
        {
            _connectionString = connectionString;
        }
        
        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            optionsBuilder.UseSqlServer(_connectionString);
        }
    }
}