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
const int N = 1e7 + 5, OO = 0x3f3f3f3f; //~1e9
// ================================================================
// link --> https://www.spoj.com/problems/FACT2/en/
//      try put wrong answer ?!

map<ll , int> primeFactorization(ll& n) {
    map < ll , int > res;

    while (n % 2 == 0) {
        res[2]++;
        n /= 2;
    }

    while (n % 3 == 0) {
        res[3]++;
        n /= 3;
    }

    // using Miller-Rabin primality test
    for(ll i = 5; i * i <= n; i+=6) {
        while (n % i == 0)
        {
            res[i]++;
            n /= i;
        }

        while (n % (i + 2) == 0)
        {
            res[i + 2]++;
            n /= (i + 2);
        }
        
    }
    if(n > 1)
        res[n]++;
    return res;
}

void solve(ll& n) {
    auto factors = primeFactorization(n);

    bool f = 1;
    for(auto i : factors) {
        if(!f)  cout << " ";
        cout << i.first << "^" << i.second;
        f = false;
    }
    cout << el;
}

int main() {
    smurf;
    ll st;
    while (cin >> st && st)
    {
        solve(st);
    }
    return 0;
    
}