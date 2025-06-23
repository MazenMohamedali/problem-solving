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

//          --> number theory helper  <--
const int MOD = 1e9 + 7;
ll add(ll a, ll b) { return ((a % MOD) + (b % MOD)) % MOD; }
ll sub(ll a, ll b) { return (((a - b) % MOD) + MOD) % MOD; }
ll mul(ll a, ll b) { return ((a % MOD) * (b % MOD)) % MOD; }
ll power(ll b, ll e)
{
    if (e == 0)
        return 1;
    ll h = power(b, e / 2);
    if (!(e & 1))
        return mul(h, h);
    return mul(mul(b, h), h);
}
ll divide(ll a, ll b) { return mul(a, power(b, MOD - 2)); }

// miller-Rabin primality test
bool isPrime(ll n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (ll i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}
// ================================================================

// bool is even = 1
ll helper(ll init, ll remind, bool isEven) {
    ll res = 0;
    if(isEven) {
        if(remind == 1)
            return res + init;
        else if(remind == 2)
            return res + 2 * init + 1;
        else 
            return res + init + (init + 1) - (init + 2);
    } else {
        if(remind == 1)
            return res - init;
        else if(remind == 2)
            return res - init - (init + 1);
        else 
            return res - init - (init + 1) + (init + 2);
    }
}

ll solve(ll init, ll n) {
    
    ll res;
    if(n % 4 == 0)
        res = 0;
    else if(n % 4 == 1)
        res = -n;
    else if(n % 4 == 2)
        res = 1;
    else    
        res = n + 1;
    
    if(init & 1)
        res = init - res;
    else 
        res += init;

    return res;
}

int main() {
    smurf;
    

    int t;
    cin >> t;

    ll init, n;
    while (t--)
    {
        cin >> init >> n;
        cout << solve(init, n) << el;
    }
    
    


    return 0;
}