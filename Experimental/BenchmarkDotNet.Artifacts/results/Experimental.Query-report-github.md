```

BenchmarkDotNet v0.13.10, Windows 11 (10.0.22631.2715/23H2/2023Update/SunValley3)
AMD Ryzen 5 5600U with Radeon Graphics, 1 CPU, 12 logical and 6 physical cores
.NET SDK 8.0.100
  [Host]   : .NET 5.0.17 (5.0.1722.21314), X64 RyuJIT AVX2
  .NET 8.0 : .NET 8.0.0 (8.0.23.53103),    X64 RyuJIT AVX2
  .NET 7.0 : .NET 7.0.14 (7.0.1423.51910), X64 RyuJIT AVX2
  .NET 5.0 : .NET 5.0.17 (5.0.1722.21314), X64 RyuJIT AVX2
  .NET 6.0 : .NET 6.0.25 (6.0.2523.51912), X64 RyuJIT AVX2


```
| Method | Job      | Runtime  | Mean     | Error   | StdDev  | Ratio | Rank |
|------- |--------- |--------- |---------:|--------:|--------:|------:|-----:|
| Parser | .NET 8.0 | .NET 8.0 | 335.0 ns | 0.77 ns | 0.64 ns |  0.69 |    1 |
| Parser | .NET 7.0 | .NET 7.0 | 419.8 ns | 3.00 ns | 2.50 ns |  0.87 |    2 |
| Parser | .NET 5.0 | .NET 5.0 | 482.3 ns | 1.65 ns | 1.38 ns |  1.00 |    3 |
| Parser | .NET 6.0 | .NET 6.0 | 502.8 ns | 7.99 ns | 6.67 ns |  1.04 |    4 |
