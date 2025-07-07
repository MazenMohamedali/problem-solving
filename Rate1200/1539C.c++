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
#include <unordered_set>
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


int solve(vl& v, ll k, ll x) {
    int n = v.size();
    if(n == 0) return 0;

    sort(all(v));
    vl diff(n - 1);
    for(int i = 0; i < n - 1; i++) diff[i] = v[i + 1] - v[i];

    sort(all(diff));

    ll groups = 1, curK = k;
    for(int i = 0; i < n - 1; i++) {
        if(diff[i] <= x) continue;

        ll needOfK = (diff[i] + x - 1) / x - 1;
        if(needOfK <= curK) curK -= needOfK;

        else groups++;
    }
    
    return groups;
}   

int main()
{
    smurf;

    int t = 1;
    while (t--)
    {
        ll n, k, x;
        cin >> n >> k >> x;
        vl nums(n);
        for(ll& i : nums) cin >> i;
        cout << solve(nums, k, x);

    }
    return 0;
}

/*

10 2 1
1 1 1 10 1 8 1 6 1 4

*/