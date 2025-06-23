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
const int N = 1e6 + 5, OO = 0x3f3f3f3f; //~1e9
// ================================================================
// link --> https://vjudge.net/problem/Gym-499179ZD

map<ll, int> curPrimeFactors;
bool perfect(ll n) {

    bool res = true;

    while (n%2 == 0)
    {
        curPrimeFactors[2]++;
        n/=2;
    }
    if(curPrimeFactors[2] & 1)   
        res = false;


    while (n%3 == 0)
    {
        curPrimeFactors[3]++;
        n/=3;
    }
    if(res && (curPrimeFactors[3] & 1))   
        res = false;

    for(ll i = 5; i*i <= n; i+=2) {
        while (n%i == 0)
        {
            curPrimeFactors[i]++;
            n/=i;
        }
        if(res && (curPrimeFactors[i] & 1))   
            res = false;
    }

    if(n > 2)
        curPrimeFactors[n]++;

    if(res && (curPrimeFactors[n] & 1))   
        res = false;
    
    return res;
}

int main() {
    smurf;
    ll n; cin >> n;
    ll x;
    for(int i =0; i<n; i++) {
        cin >> x;
        cout << (perfect(x) ? "YES": "NO") << el;
    }
    return 0;
}