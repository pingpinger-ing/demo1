int total = 0;
            IList<int> list = new List<int>(100000000);
            //Partition, parallel computing 1000000000000
            Parallel.For(0, 100000000//Accumulation of arrays
                         , () => { return 1; } //Partition initialization data
            , (index, loop, local) =>
            {
                lock (list)
                {
                    list.Add(System.Threading.Thread.CurrentThread.ManagedThreadId);
                }
                Console.WriteLine(System.Threading.Thread.CurrentThread.ManagedThreadId);
                return local += index;//Execute separately for each partition
            }
            , local/*Results of each partition*/ => { System.Threading.Interlocked.Add(ref total, local); });//Summarize partition results
            Console.WriteLine("parallelism" + total);
 
            total = 0;
            for (int i = 0; i < 100000000; i++)
            {
                total += i;
            }
 
            IEnumerable<int> iee = list.Distinct();
 
            Console.WriteLine("sequence：" + total);
            Console.ReadKey();
