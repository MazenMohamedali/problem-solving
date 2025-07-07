using System.Diagnostics.Contracts;

namespace problens
{

    public class CF1734C
    {
        public long Solve(ref string numbers)
        {
            long ans = 0;
            int n = numbers.Length;
            int[] Op = new int[n];
            for (int i = 0; i < n; ++i)
            {
                if (numbers[i] != '0') continue;
                int curIncrement = i + 1;
                for (int j = i; j < n && numbers[j] != '1'; j += curIncrement)
                    if (j < n && Op[j] == 0) Op[j] = curIncrement;
            }

            foreach (int i in Op) ans += i;

            return ans;
        }
    }

    static class Program
    {
        private static void Main3(string[] args)
        {
            if (!int.TryParse(Console.ReadLine(), out int t)) return;
            while (t-- > 0)
            {
                int n = Convert.ToInt32(Console.ReadLine());
                string s = Console.ReadLine() ?? string.Empty;
                CF1734C sol = new CF1734C();
                Console.WriteLine(sol.Solve(ref s));
            }
        }
    }
}