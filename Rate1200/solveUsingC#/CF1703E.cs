using System.Numerics;

namespace problens
{
    public class CF1703E
    {
        private readonly int _n;
        private readonly bool[,] _grid;
        private readonly bool[,] _visited;

        public CF1703E(bool[,] grid, int size)
        {
            _n = size;
            _grid = grid;
            _visited = new bool[_n, _n];
        }

        public int Solve()
        {
            int changes = 0;
            int half = (_n + 1) / 2;

            for (int r = 0; r < half; ++r)
            {
                for (int c = 0; c < half; ++c)
                {
                    if (_visited[r, c]) continue;

                    var rotations = new (int r, int c)[]
                    {
                        (r, c),
                        (c, _n - 1 - r),
                        (_n - 1 - r, _n - 1 - c),
                        (_n - 1 - c, r)
                    };


                    int ones = 0, zeros = 0;
                    foreach (var (x, y) in rotations)
                    {
                        if (_visited[x, y]) continue;
                        _visited[x, y] = true;
                        if (_grid[x, y]) ones++;
                        else zeros++;
                    }


                    changes += Math.Min(ones, zeros);
                }
            }

            return changes;
        }
    }

    internal class Program1703
    {
        public static void Main2()
        {
            if (!int.TryParse(Console.ReadLine(), out int t)) return;
            while (t-- > 0)
            {
                if (!int.TryParse(Console.ReadLine(), out int n)) return;

                bool[,] mirrorGrid = new bool[n, n];
                for (int i = 0; i < n; i++)
                {
                    string line = Console.ReadLine() ?? string.Empty;
                    for (int j = 0; j < n; j++)
                        mirrorGrid[i, j] = (line[j] == '1');
                }

                CF1703E sol = new CF1703E(mirrorGrid, n);
                Console.WriteLine(sol.Solve());
            }
        }
    }
}