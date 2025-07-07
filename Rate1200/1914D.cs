// using System.ComponentModel.DataAnnotations;

// namespace Solutions
// {
//     class Program
//     {
//         public static List<(int value, int idx) > n1, n2, n3;
//         private static int CompareDescending(int a, int b) => b.CompareTo(a);
//         private static long Solve()
//         {
//             long ans = 0;
//             for (int i = 0; i < 3; i++)
//             {
//                 for (int j = 0; j < 3; j++)
//                 {
//                     for (int k = 0; k < 3; k++)
//                     {
//                         if (n1[i].idx == n2[j].idx
//                          || n2[j].idx == n3[k].idx
//                          || n1[i].idx == n3[k].idx)
//                             continue;
//                         ans = Math.Max(ans, n1[i].value + n2[j].value + n3[k].value);
//                     }
//                 }
//             }
//             return ans;
//         }
//         public static void Main2(string[] args)
//         {
//             int t = Convert.ToInt32(Console.ReadLine());
//             while (t-- > 0)
//             {
//                 int n = Convert.ToInt32(Console.ReadLine());
//                 n1 = new List<(int value, int idx)>(new (int, int)[n]);
//                 n2 = new List<(int value, int idx)>(new (int, int)[n]);
//                 n3 = new List<(int value, int idx)>(new (int, int)[n]);

//                 var row1 = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
//                 for (int i = 0; i < n; i++)
//                     n1[i] = (row1[i], i);

//                 var row2 = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
//                 for (int i = 0; i < n; i++)
//                     n2[i] = (row2[i], i);

//                 var row3 = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
//                 for (int i = 0; i < n; i++)
//                     n3[i] = (row3[i], i);

//                 n1.Sort((a, b) => CompareDescending(a.value, b.value));
//                 n2.Sort((a, b) => CompareDescending(a.value, b.value));
//                 n3.Sort((a, b) => CompareDescending(a.value, b.value));

//                 Console.WriteLine(Solve());
//             }
//         }
//     }
// }