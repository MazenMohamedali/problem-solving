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

bool isPrime(ll n) {
    if(n < 2) return false;
    if(n % 2 == 0)  return n == 2;

    for(ll i = 3; i * i <= n; i += 2) {
        if(n % i == 0)
            return false;
    }

    return true;
}

pair<int, int> solve(int n) {
    if(n % 2 == 0) 
        return {n / 2, n / 2};
    
    if(isPrime(n))
        return {1, n - 1};
    
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            int a = n / i;
            return {a, n - a};
        }
    }
    return {1, n - 1};
}


int main() {
    smurf;

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        auto ans = solve(n);
        cout << ans.first << " " << ans.second << el;
    }
    


    return 0;
}
