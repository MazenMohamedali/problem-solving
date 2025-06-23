#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
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
#define f first
#define s second
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
const int N = 2e5 + 10, OO = 0x3f3f3f3f; //~1e9
// =================================================================================================================================
// link --> https://cses.fi/problemset/task/1623

ll total = 0, minDiff;
int n, arr[22];
void solve(int i, ll s1)
{
    if (i == n)
    {
        ll s2 = total - s1;
        minDiff = min(abs(s1 - s2), minDiff);
        return;
    }

    solve(i + 1, s1 + arr[i]);
    solve(i + 1, s1);
}

int main()
{
    smurf;
    // freopen("inp.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        total += arr[i];
    }

    minDiff = total;
    solve(0, 0);
    cout << minDiff << el;
}