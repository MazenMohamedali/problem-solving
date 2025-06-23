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
typedef __int128 ull;
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
#include <string>
#include <cstdint>
// ========================================================================================================================

ll solve(string s) {
    int longestCons1s = 0;
    int n = s.size();

    int curr1s = 0;
    for(int i = 0; i <= n; i++) {
        if(i < n && s[i] == '1') curr1s++;
        else {
            longestCons1s = max(curr1s, longestCons1s);
            curr1s = 0;
        }
    }

    if(longestCons1s == n)
        return (ll)longestCons1s * (ll)longestCons1s;

    if(s[n - 1] == '1' && s[0] == '1') {
        int lastOnes = 0;
        for(int i = n - 1; i >= 1 && s[i] == '1'; i--)
            lastOnes++;
        
        int firs1s = 0;
        for(int i = 0; i < n - 2 && s[i] == '1'; i++)
            firs1s++;

        longestCons1s = max(longestCons1s, lastOnes + firs1s);
    }

    ll x = longestCons1s + 1;
    return (x * x) / 4LL;
}   


int main() {
    smurf;
   
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << solve(s) << el;
    }
    
    
    return 0;
}
