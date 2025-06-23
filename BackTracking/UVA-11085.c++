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
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef vector<vs> vvs;
const int N = 1e6 + 5, OO = 0x3f3f3f3f; //~1e9
// =================================================================================================================================
// link --> 11085 - Back to the 8-Queens

int n = 9;

bool validCeil(vi &pos, int ceil) {
    int r = pos[ceil];
    int c = ceil;

    for (int i = 1; i < c; i++) {
        if (pos[i] == r || abs(r - pos[i]) == abs(c - i)) {
            return false;
        }
    }
    return true;
}

int minRes = OO;
void solve(vi &pos, int moves, int currQ) {
    if (currQ > n - 1) {
        minRes = min(minRes, moves);
        return;
    }

        for (int i = 1; i < n; i++) {
            int prev = pos[currQ];
            bool add = (i == prev) ? 0 : 1;
            pos[currQ] = i;
            if(validCeil(pos, currQ))
                solve(pos, moves + add, currQ + 1);
            pos[currQ] = prev;
    }
}

int main() {
    smurf;
    // freopen("inp.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    vi g(n);
    int i = 1;
    int c = 1;
    while (cin >> g[i])
    {
        for (int i = 2; i < n; i++)
            cin >> g[i];
        solve(g, 0, 1);
        cout << "Case " << c++ << ": " << minRes << el;
        minRes = OO;
        i = 1;
    }
    

    return 0;
}