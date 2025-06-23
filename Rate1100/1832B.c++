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


ll solve(int k , vl& v) {
    ll minSum = 1e18;
    int n = v.size();
    sort(all(v));
    for(int i = 1; i < n; i++) v[i] += v[i - 1];

    for(int i = 0; i <= k; i++) {
        int x = k - i;
        ll f1 = i != 0 ? v[2 * i - 1] : 0;
        ll f2 = x != 0 ? v[n - 1] - v[n - x - 1] : 0;
        minSum = min(f1 + f2, minSum);
    }
    return v[n - 1] - minSum;
}


int main() {
    smurf;
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vl v(n);
        for(ll& i : v) cin >> i;
        cout << solve(k, v) << el;
    }
    
    return 0;
}