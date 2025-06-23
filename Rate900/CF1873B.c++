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

int solve(string& s) {

    int n = s.size();
    set<int> res;
    int last = 1;
    res.insert(last);

    for(int i = 0 ; i < n; i++) {
        if(s[i] == '<') {
            auto it = res.upper_bound(last);
            if(it == res.end()) 
                res.insert(++last);
            else last = *it;
        }
        else {
            auto it = res.lower_bound(last);
            if(it == res.begin()) 
                res.insert(--last);
            // --it;
            else last = *(--it);
        }
    }

    return res.size();
}



int solve2(string& s) {

    int n = s.size();
    int res = 1, maxSame = 1;
    for(int i = 1; i < n; ++i) {
        if(s[i - 1] == s[i])
            maxSame++;
        else {
            res = max(maxSame, res);
            maxSame = 1;
        }
    }
    res = max(maxSame, res);

    return res + 1;
}

int main() {
    smurf;
    
    int t, n;
    string s;
    cin >> t;
    
    while (t--) {
        cin >> n >> s;
        cout << solve2(s) << el;
    }
    
    return 0;
}