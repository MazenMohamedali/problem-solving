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
#define sortD(v)    sort(all(v), greater<int>())

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
// link --> https://codeforces.com/problemset/problem/1490/D

int k = 9 + 1;
vector<vi> KofPre(k, vi(N));
int g(int n) {
    if (n < 10) {
        return n;
    }   
    
    ll prod = 1;
    while (n) {
        int digit = n % 10;
        if (digit != 0)
            prod *= digit;
        n /= 10;
    }
    return g(prod);
}

void solve() {
    for(int i = 1; i < N; i++)  {
        int res = g(i);
        KofPre[res][i] = 1;
    }

    for(int i = 0; i<k; i++) {
        for(int j = 1; j < N; j++)
            KofPre[i][j] += KofPre[i][j - 1];
    }
}

int finalSolution(int l, int r, int k) {
    if(l == 1)  return KofPre[k][r];
    return KofPre[k][r] - KofPre[k][l - 1];
}   

int main()
{
    smurf;
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);


    solve();
    int q, l, r, k;  cin >> q;
    while (q --> 0)
    {
        cin >> l >> r >> k;
        cout << finalSolution(l, r, k) << el;
    }

    return 0;
}