/*================================================================
						  يا رب
				اللهم صلي علي سيدنا محمد
==================================================================
					بسم الله الرحمن الرحيم

					 الْحَمْدُ لِلَّهِ رَبِّ الْعَالَمِينَ

						الرَّحْمَنِ الرَّحِيم

						مَالِكِ يَوْمِ الدِّين

					إِيَّاكَ نَعْبُدُ وَإِيَّاكَ نَسْتَعِينُ

					اهدِنَا الصِّرَاطَ الْمُسْتَقِيمَ

		صِرَاطَ الَّذِينَ أَنْعَمْتَ عَلَيْهِمْ غَيْرِ الْمَغْضُوبِ عَلَيْهِمْ وَلاَ الضَّالِّينَ

==================================================================*/

using System.ComponentModel;

namespace Problems
{
    class CF1420B
    {
        private int _n;
        private long[] an;

        public int NumberOfElements
        {
            get { return _n; }
            set { _n = value; }
        }

        public long[] ElementsArray
        {
            get => an;
            set => an = value;
        }

        public long Solve()
        {
            long ans = 0;
            Dictionary<int, int> firstOnes = new Dictionary<int, int>();
            foreach (int val in an)
            {
                for (int i = 31; i >= 0; i--)
                {
                    if ((val & (1 << i)) != 0)
                    {
                        if (!firstOnes.ContainsKey(i)) firstOnes[i] = 0;
                        firstOnes[i]++;
                        break;
                    }
                }
            }

            foreach (var cntr in firstOnes)
                ans += cntr.Value * (long)(cntr.Value - 1) / 2;


            return ans;
        }

    }
    class Program1420B
    {
        internal static void Main(string[] args)
        {
            if (!int.TryParse(Console.ReadLine(), out int t)) return;
            CF1420B Solver = new CF1420B();
            while (t-- > 0)
            {
                if (!int.TryParse(Console.ReadLine(), out int n)) return;
                long[] numbers = Console.ReadLine().Split(' ').Select(long.Parse).ToArray();
                Solver.ElementsArray = numbers;
                Console.WriteLine($"{Solver.Solve()}");
            }
        }   
    }
}