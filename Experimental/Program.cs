using BenchmarkDotNet.Attributes;
using BenchmarkDotNet.Jobs;
using BenchmarkDotNet.Running;
using System;
using System.Linq;
using System.Numerics;

namespace Experimental
{
    internal class Program
    {
        static void Main()
        {
            BenchmarkRunner.Run<Query>();
        }
    }

    // [MemoryDiagnoser]
    [SimpleJob(runtimeMoniker: RuntimeMoniker.Net50, baseline: true)]
    [SimpleJob(runtimeMoniker: RuntimeMoniker.Net60)]
    [SimpleJob(runtimeMoniker: RuntimeMoniker.Net70)]
    [SimpleJob(runtimeMoniker: RuntimeMoniker.Net80)]
    [Orderer(BenchmarkDotNet.Order.SummaryOrderPolicy.FastestToSlowest)]
    // [MarkdownExporterAttribute, AsciiDocExporterAttribute, HtmlExporterAttribute, CsvExporterAttribute, RPlotExporterAttribute]
    [RankColumn]
    public class Query
    {
        [Benchmark]
        public void Parser()
        {
            var dateTimes = new string[] { "2021-01-01", "2021-01-02", "2021-01-03" };
            foreach (var dateTime in dateTimes)
            {
                var date = DateTime.Parse(dateTime);
            }
        }
    }
}