// using BenchmarkDotNet.Attributes;
// using BenchmarkDotNet.Jobs;
// using BenchmarkDotNet.Running;
// using System;
// using System.Linq;
// using System.Numerics;

// namespace Experimental
// {
//     internal class Program
//     {
//         public static void Main()
//         {
//             BenchmarkRunner.Run<Query>();
//         }
//     }
//     [MemoryDiagnoser(false)]
//     [SimpleJob(runtimeMoniker: RuntimeMoniker.Net50, baseline: true)]
//     [SimpleJob(runtimeMoniker: RuntimeMoniker.Net60)]
//     [SimpleJob(runtimeMoniker: RuntimeMoniker.Net70)]
//     [SimpleJob(runtimeMoniker: RuntimeMoniker.Net80)]
//     [Orderer(BenchmarkDotNet.Order.SummaryOrderPolicy.FastestToSlowest)]
//     // [MarkdownExporterAttribute, AsciiDocExporterAttribute, HtmlExporterAttribute, CsvExporterAttribute, RPlotExporterAttribute]
//     [RankColumn]
//     public class Query
//     {
//         [Benchmark]
//         public void Parser()
//         {
//             var dateTimes = new string[] { "2021-01-01", "2021-01-02", "2021-01-03" };
//             foreach (var dateTime in dateTimes)
//             {
//                 var date = DateTime.Parse(dateTime);
//             }
//         }
//     }
// }

using System;
using System.Diagnostics;

namespace Experimental
{
    internal class Program
    {
        public static void Main()
        {
            PerformanceCounter gpuCounter = new PerformanceCounter("GPU Engine", "% Utilization", "0", true);
            float gpuPercentage = gpuCounter.NextValue();
            Console.WriteLine($"GPU Percentage: {gpuPercentage}%");
        }
    }
}