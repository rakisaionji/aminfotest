using System;

class Program
{
    static void Main(string[] args)
    {
        Console.WriteLine($"Version      =  {Environment.OSVersion.VersionString}");
        Console.WriteLine($"MachineName  =  {Environment.MachineName}");
        Console.WriteLine($"UserName     =  {Environment.UserName}");
        Console.WriteLine();
        Console.ReadLine();
    }
}
