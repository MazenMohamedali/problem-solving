using Microsoft.VisualBasic;

namespace problens
{
    internal class CF1692E
    {
        private int[] _numbers;
        private int _n;
        private int _t;
        public int[] Numbers
        {
            get => _numbers;
            set
            {
                _numbers = value ?? Array.Empty<int>();
                _n = _numbers.Length;
            }
        }
        public int Target
        {
            get => _t;
            set => _t = value;
        }

        public CF1692E(int[] a, int t)
        {
            Numbers = a;
            _n = a.Length;
            _t = t;
        }
        
        public CF1692E() {}

        public int Solve()
        {
            int Maxlen = 0;
            Dictionary<int, int> Have = new Dictionary<int, int> {[0] = -1};


            int Prefix = 0;
            for (int i = 0; i < _n; ++i)
            {
                Prefix += Numbers[i];
                if (!Have.ContainsKey(Prefix))
                    Have[Prefix] = i;

                int target = Prefix - _t;
                if(target == 0) Math.Max(Maxlen, i + 1);
                if (Have.TryGetValue(target, out int val))
                    Maxlen = Math.Max(Maxlen, i - val);
            }

            return Maxlen == 0 ? -1 : _n - Maxlen;
        }
    }   

    internal class Program1692
    {
        public static void Main2()
        {
            if (!int.TryParse(Console.ReadLine(), out int t)) return;
            CF1692E Solver = new CF1692E();
            while (t-- > 0)
            {
                var nt = Console.ReadLine()?.Split(' ').Select(int.Parse).ToArray();
                int n = nt[0], target = nt[1];

                var numbers = Console.ReadLine()?.Split(' ').Select(int.Parse).ToArray();
                Solver.Numbers = numbers;
                Solver.Target = target;
                Console.WriteLine(Solver.Solve());
            }
        } 
    }
}