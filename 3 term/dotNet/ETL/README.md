# ETL

ETL is a service that monitors some FTP-server and move files from one site to another. 

Moving with encryption, compression and saving all the info in database

## Installation

### Before the usage make sure that you have installed all the necessary staff.

### Pull and run Docker container image

Firstly, you need a Docker to be [installed](https://www.docker.com/products/docker-desktop). 

Then you pull the SQL Server Linux container image from Microsoft Container Registry.

```bash
sudo docker pull microsoft/mssql-server-linux:2017-latest
```

To run the container image with Docker, you can use the following command from a bash shell (Linux/macOS) or elevated PowerShell command prompt.

```bash
sudo docker run -e 'SERVER_NAME' -e 'ACCEPT_EULA=Y' -e 'SA_PASSWORD=yourStrongPassword' \
   -p 1433:1433 --name sql1 -h sql1 \
   -d microsoft/mssql-server-linux
```

|Parameter                                  |Description|
|-------------------------------------------|-----------|
|-e 'SERVER_NAME'                           |MS-SQL Server name of your server             
|-e "ACCEPT_EULA=Y"                         |Set the ACCEPT_EULA variable to any value to confirm your acceptance of the [End-User Licensing Agreement](https://go.microsoft.com/fwlink/?LinkId=746388). Required setting for the SQL Server image.           |
|'SA_PASSWORD=yourStrongPassword'    |Specify your own strong password that is at least 8 characters and meets the [SQL Server password requirements](https://docs.microsoft.com/en-us/sql/relational-databases/security/password-policy?view=sql-server-ver15). Required setting for the SQL Server image.           |
|-p 1433:1433                               |Map a TCP port on the host environment (first value) with a TCP port in the container (second value). In this example, SQL Server is listening on TCP 1433 in the container and this is exposed to the port, 1433, on the host.           |
|--name sql1                                |Specify a custom name for the container rather than a randomly generated one. If you run more than one container, you cannot reuse this same name.           |
|-h sql1                                    |Used to explicitly set the container hostname, if you don't specify it, it defaults to the container ID which is a randomly generated system GUID.           |
|mcr.microsoft.com/mssql/server:2019-latest |The SQL Server 2019 Ubuntu Linux container image.           |

To view your Docker containers, use the docker ps command:
```bash
sudo docker ps -a
```

### Connect* to SQL Server
#### ! Volantary on *this* project – you can do it in the next .Net step

Use the docker exec -it command to start an interactive bash shell inside your running container:
```bash
sudo docker exec -it sql1 "bash"
```

Once inside the container, connect locally with sqlcmd. Sqlcmd is not in the path by default, so you have to specify the full path.
```bash
/opt/mssql-tools/bin/sqlcmd -S localhost -U SA -P "yourStrongPassword"
```

If successful, you should get to a sqlcmd command prompt: 1>.

### .Net core

You need .Net Runtime and SDK to be [installed](https://dotnet.microsoft.com/download).

Create an executable .Net Core solution. 

Create some projects and add to the project with DbContext EntityFramework Core packages:
- Microsoft.EntityFrameworkCore
- Microsoft.EntityFrameworkCore.SqlServer
- System.Data.SqlClient

Also you need a class that inherits DbContext class and override OnConfiguring() method:

```c#
using Microsoft.EntityFrameworkCore;

namespace YourNamespace
{
    public class YourContext : DbContext
    {
        DbSet<YourEntity> YourEntities { get; set; }

        private string _connectionString;
        
        public YourContext(string connectionString)
        {
            _connectionString = connectionString;
        }
        
        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            optionsBuilder.UseSqlServer(_connectionString);
        }
    }
}
```

And define context and connection string : usage example

```c#
    // Build connection string
    SqlConnectionStringBuilder Builder = new SqlConnectionStringBuilder() 
    {
        DataSource = "localhost";
        UserID = "sa";
        Password = "yourStrongPassword";
        InitialCatalog = "NameofYourDb"; 
    };
                
     // Define context & etc.
     YourContext Context = new YourContext(Builder.ConnectionString);
     MoveDb moveToDbClass = new MoveDb(Context);
```

Then create additional functionality: Archive, Encryption and others and create {0}Options classes for them.

```c#
public static class Archive
{
    public static void Compress(string source, string target, CompressionLevel level)
    {
       using var sourceStream = new FileStream(source, FileMode.Open);
       using var targetStream = File.Create(target
       using var zipStream = new GZipStream(targetStream, level);
       sourceStream.CopyTo(zipStream);
    }
        
    public static void Decompress(string source, string target)
    {
       using var sourceStream = new FileStream(source, FileMode.OpenOrCreate);
       using var targetStream = File.Create(target);
       using var zipStream = new GZipStream(sourceStream, CompressionMode.Decompress);
       zipStream.CopyTo(targetStream);
    }
}

public class ArchiveOptions : Options
{
   public CompressionLevel CompressionLevel { get; set; } = CompressionLevel.Optimal;
}
```

Next create some classes for serialize json and xml, different converters and parsers. In a word – create!


## Usage

#### To run app do the following things:
- Run Docker and container with your database
- Connect to your database
- Run .Net Core app

```bash
dotnet run
```


#### Hear we go, my congrats! ✨

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update all the requirement instruments as appropriate.

## License
[Apache License 2.0](https://choosealicense.com/licenses/apache-2.0/)
