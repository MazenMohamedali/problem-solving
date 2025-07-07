using System.Diagnostics.Contracts;

namespace problens
{

    public class CF1704C
    {
        public long Solve(ref int[] infected, int n)
        {
            List<int> gaps = new List<int>();
            int m = infected.Length;
            Array.Sort(infected);

            for (int i = 0; i < m - 1; i++)
                gaps.Add(infected[i + 1] - infected[i] - 1);
            gaps.Add(infected[0] + n - infected[m - 1] - 1);

            gaps.Sort((a, b) => b.CompareTo(a));

            int days = 0, notInfected = 0;
            foreach (var gap in gaps)
            {
                int curGap = gap - days * 2;
                if (curGap > 0)
                {
                    notInfected++;
                    days++;
                    curGap -= 2;
                    if (curGap > 0)
                    {
                        notInfected += curGap;
                        days++;
                    }
                }
            }

            return n - notInfected;
        }
    }

    static class CF1704
    {
        private static void Main2(string[] args)
        {
            if (!int.TryParse(Console.ReadLine(), out int t)) return;
            while (t-- > 0)
            {
                var nm = Console.ReadLine()?.Split(' ', StringSplitOptions.RemoveEmptyEntries);
                int n = int.Parse(nm[0]);
                int m = int.Parse(nm[1]);

                var infectedRow = Console.ReadLine()?.Split(' ', StringSplitOptions.RemoveEmptyEntries);
                if (infectedRow == null || infectedRow.Length < m) return;

                int[] infected = new int[m];
                for (int i = 0; i < m; ++i) infected[i] = int.Parse(infectedRow[i]);

                CF1704C Sol = new CF1704C();
                Console.WriteLine(Sol.Solve(ref infected, n));
            }
        }
    }
}
