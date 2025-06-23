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
#include <string>
#include <cstdint>

// ================================================================

ll MaxiDiff(vl &a) {
    int n = a.size();
    ll ans = 0;

    for(int i = 1; i < n; ++i)
        a[i] += a[i - 1];

    for(int i = 1; i < n; i++) {

        if(n % i != 0) continue;
        ll mini = LLONG_MAX, maxi = 0;

        for(int j = 0; j < n; j += i) {
            ll currN = a[j + i - 1] - (j > 0 ? a[j - 1] : 0);
            mini = min(currN, mini);
            maxi = max(currN, maxi);
        }

        ans = max(ans, maxi - mini);
    }

    return ans;
}   


int main()
{
    smurf;

    int t;
    cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vl a(n);
        for (ll &i : a)
            cin >> i;
        cout << MaxiDiff(a) << el;
    }

    return 0;
}

/*

1
6
10 2 3 6 1 3


*/