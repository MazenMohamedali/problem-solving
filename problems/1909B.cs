using System.ComponentModel.DataAnnotations;

namespace Solutions
{

    class solution
    {
        public long solve(ref List<long> l)
        {
            for (int i = 0; (1L << i) <= 1e18; i++)
            {
                long dist1 = -1, dist2 = -1;
                bool isAns = true;
                foreach (long ele in l)
                {
                    long curN = ele % (1L << i);
                    if (dist1 == -1 || dist2 == -1)
                    {
                        if (dist1 == -1) dist1 = curN;
                        else
                        {
                            if (dist1 != curN)
                                dist2 = curN;
                        }
                    }
                    else
                    {
                        if ((dist1 != curN) && (dist2 != curN))
                        {
                            isAns = false;
                            break;
                        }
                    }
                }

                if (isAns && dist2 != -1) return (1L << i);
            }
            return 0;
        }
    }

    class CF1909B
    {
        public static void Main3()
        {
            int t = Convert.ToInt32(Console.ReadLine());
            while (t-- > 0)
            {
                int n = Convert.ToInt32(Console.ReadLine());
                List<long> numbers = new List<long>(new long[n]);
                numbers = Console.ReadLine().Split(' ').Select(long.Parse).ToList();
                solution sol = new solution();
                Console.WriteLine(sol.solve(ref numbers));
            }
        }
    }
}