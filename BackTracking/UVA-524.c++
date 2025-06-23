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



unordered_map<int, int> levels;
void solve(vi& nodeData, int l, int r, int level) {

    if(l >= nodeData.size() || r < 0 || l > r)// || l < 0 || r >= nodeData.size()
        return;
    
    
    auto maxIte = max_element(nodeData.begin() + l, nodeData.begin() + r + 1);
    int maxIdx = distance(nodeData.begin(), maxIte);

    levels[*maxIte] = level;

    solve(nodeData, l, maxIdx - 1, level + 1);
    solve(nodeData, maxIdx + 1, r, level + 1);
}
int main()
{
    smurf;
    // freopen("inp.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int t, n; cin >> t;
    while (t-- > 0)
    {
        cin >> n;
        vi items(n);
        for(int& i : items) cin >> i;

        solve(items, 0, n - 1, 0);

        for(int i : items)
            cout << levels[i] << " ";
        cout << el;
        levels.clear();
    }
    return 0;
}