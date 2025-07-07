using System.ComponentModel.DataAnnotations;

namespace Solutions
{
    class Program
    {
        private static long ans;

        private static int CompareDescending(int a, int b) => b.CompareTo(a);

        private static void Solve(int i, ref List<(int value, int idx, int abc)> all, ref bool[] abc, ref bool[] indexes, long sum)
        {
            if (abc[0] && abc[1] && abc[2])
            {
                ans = Math.Max(ans, sum);
                return;
            }
            if (i >= all.Count) return;

            var (curn, idx, curabc) = all[i];

            if (!indexes[idx] && !abc[curabc])
            {
                abc[curabc] = true;
                indexes[idx] = true;
                Solve(i + 1, ref all,ref abc, ref indexes, sum + curn);
                abc[curabc] = false;
                indexes[idx] = false;
            }

            Solve(i + 1, ref all, ref abc, ref indexes, sum);
        }
        public static void Main2(string[] args)
        {
            int t = Convert.ToInt32(Console.ReadLine());
            while (t-- > 0)
            {
                int n = Convert.ToInt32(Console.ReadLine());
                var n1 = new List<(int value, int idx)>(new (int, int)[n]);
                var n2 = new List<(int value, int idx)>(new (int, int)[n]);
                var n3 = new List<(int value, int idx)>(new (int, int)[n]);

                var row1 = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
                for (int i = 0; i < n; i++)
                    n1[i] = (row1[i], i);

                var row2 = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
                for (int i = 0; i < n; i++)
                    n2[i] = (row2[i], i);

                var row3 = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
                for (int i = 0; i < n; i++)
                    n3[i] = (row3[i], i);

                n1.Sort((a, b) => CompareDescending(a.value, b.value));
                n2.Sort((a, b) => CompareDescending(a.value, b.value));
                n3.Sort((a, b) => CompareDescending(a.value, b.value));

                var all = new List<(int value, int idx, int abc)>();
                for (int i = 0; i < 3; i++)
                {
                    all.Add((n1[i].value, n1[i].idx, 0));
                    all.Add((n2[i].value, n2[i].idx, 1));
                    all.Add((n3[i].value, n3[i].idx, 2));
                }

                ans = 0;
                var abc = new bool[3];
                var indexes = new bool[n + 1];
                Solve(0, ref all, ref abc, ref indexes, 0);
                Console.WriteLine(ans);
            }
        }
    }
}