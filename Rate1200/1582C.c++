#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <deque>
#include <bitset>
#include <limits>
#include <numeric>
#include <cstring>
#include <iomanip>
#include <unordered_set>
using namespace std;

#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define clr(v, d) memset(v, d, sizeof(v))
#define repi(i, j, n) for (int i = (j); i < (int)(n); ++i)
#define repd(i, j, n) for (int i = (j); i >= (int)(n); --i)
#define repa(v) repi(i, 0, sz(v)) repi(j, 0, sz(v[i]))
#define rep(i, v) repi(i, 0, sz(v))
#define lp(i, cnt) repi(i, 0, cnt)
#define lpi(i, s, cnt) repi(i, s, cnt)
#define P(x) cout << #x << " = { " << x << " }\n"
#define pb push_back
#define sortD(v) sort(all(v), greater<int>())

// #define f first
// #define s second
#define MP make_pair
#define el '\n'
#define arrow "---->"
#define smurf                    \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<double> vd;
typedef vector<bool> vb;
typedef vector<long long> vll;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef vector<vs> vvs;
const int OO = 0x3f3f3f3f; //~1e9

// ================================================================


string s;
int solve(int i, int j, char CurrLetter, int ans) {
    if(i >= j) return ans;
    if(s[i] == s[j]) return solve(i + 1, j - 1, CurrLetter, ans);
    
    int ans1, ans2;
    if(CurrLetter == ' ') {
        ans1 = solve(i + 1, j, s[i], ans + 1);
        ans2 = solve(i, j - 1, s[j], ans + 1);
    } else {
        if(s[i] == CurrLetter) return solve(i + 1, j , CurrLetter, ans + 1);
        else if(s[j] == CurrLetter) return solve(i, j - 1 , CurrLetter, ans + 1); 
        else {
            i = s.size() + 1;
            ans -= ans;
            ans--;
            return solve(i, j - 1 , CurrLetter, ans); 
        }
    }

    return ans1 == -1 ? ans2 : ans2 == -1 ? ans1 : min(ans1, ans2);
}   

int main()
{
    smurf;

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        s.reserve(n);
        cin >> s;
        cout << solve(0, n - 1, ' ', 0) << el;
    }
    return 0;
}
