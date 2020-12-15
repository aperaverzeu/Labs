using ETL.Models;
using Microsoft.EntityFrameworkCore;

namespace ETL.DataAccess
{
    public class DbConnectionOptionContext : DbContext
    {
        public DbSet<DbConnectionModel> DbConnectionOptions { get; set; }

        public string _connectionString;

        public DbConnectionOptionContext(string connectionString)
        {
            _connectionString = connectionString;
        }
        
        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            optionsBuilder.UseSqlServer(_connectionString);
        }
    }
}