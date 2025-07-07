using System;
using System.Numerics;


namespace Problems
{
    class CF1594C
    {
        private string _have;
        private char _need;
        public string Have
        {
            get
            {
                return _have;
            }

            set
            {
                _have = value;
            }
        }

        public char Need
        {
            get => _need;
            set => _need = value;
        }


        public CF1594C(string have, char need)
        {
            Have = have;
            Need = need;
        }
        public CF1594C(){}

        public List<int> Solve()
        {
            bool chages = false;
            foreach (var i in Have)
                if (i != Need)
                {
                    chages = true;
                    break;
                }

            if (!chages) return new List<int>() { 0 };

            List<int> ans = new List<int>();
            int n = Have.Length;
            int minOp = n + 1;
            int iMinOp = -1;
            for (int i = 2; i <= n; i++)
            {
                int curOp = 0;
                for (int j = i; j <= n; j += i)
                {
                    if (Have[j - 1] != Need) curOp++;
                }

                if (curOp == 0) { return new List<int>(){i}; }
            }

            ans.Add(iMinOp);
            if (minOp == 0) return ans;

            return new List<int>() { n - 1, n };
        }   
        
    }
    class Program1594C
    {
        internal static void Main3()
        {
            if (!int.TryParse(Console.ReadLine(), out int t)) return;
            CF1594C Solver = new CF1594C();
            while (t-- > 0)
            {
                var nc = Console.ReadLine().Split();
                int n = int.Parse(nc[0]);
                char c = nc[1][0];
                string s = Console.ReadLine();

                Solver.Have = s;
                Solver.Need = c;
                var ans = Solver.Solve();

                int sz = ans.Count;
                if (sz == 1 && ans[0] == 0)
                {
                    Console.WriteLine(0);
                    continue;
                }

                Console.WriteLine($"{sz}");
                foreach (var i in ans) Console.Write($"{i} ");
                Console.WriteLine();
            }
        }
    }
}
