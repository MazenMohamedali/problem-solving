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
vl solve(ll n, ll k, ll b, ll s) {
    vl res(n, 0);
    
    ll miniS = k * b;
    ll maxS = (k * b) + (k - 1) * n;

    if(s < miniS || s > maxS) return {-1};

    if(s <= (k * b) + (k - 1) ) {
        res[0] = s;
        return res;
    }

    res[0] = (k * b) + (k - 1);
    s -= res[0];
    for(int i = 1; i < n && s > 0; i++) {
        if(s >= k - 1) 
            res[i] = k - 1;
        else    
            res[i] = s;

        s -= res[i];
    }

    return res;
}


int main() {
    smurf;

    int t;
    cin >> t;
    while (t--)
    {
        ll n, k, b, s;
        cin >> n >> k >> b >> s;
        vl res = solve(n, k, b , s);

        for(ll i : res)
            cout << i << ' ';

        cout << el;
    }


    return 0;
}