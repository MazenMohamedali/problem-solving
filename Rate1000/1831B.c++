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
typedef vector<vb> vvb;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef vector<vs> vvs;
const int OO = 0x3f3f3f3f; //~1e9

// ================================================================


map<int, int> consequative(vi& a) {
    int n = a.size();
    map<int, int> res;


    int j = 0;
    for(int i = 0;  i <= n; i++) {
        if(i == n || a[j] != a[i]) {
            res[a[j]] = max(res[a[j]], i - j);
            j = i;
        }
    }

    return res;
}


int solve(vi& a1, vi& a2) {
    int res = 0;
    map<int, int> consA1 = consequative(a1), consA2 = consequative(a2);

    for(auto& [f, s] : consA1) 
        res = max(res, s + consA2[f]);

    for(auto& [f, s] : consA2) 
        res = max(res, s + consA1[f]);
    
    return res;
}


int main() {
    smurf;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi a1(n), a2(n);
        
        for(int& i : a1)
            cin >> i;

        for(int& i : a2)
            cin >> i;

        cout << solve(a1, a2) << el;
    }

    return 0;
}
