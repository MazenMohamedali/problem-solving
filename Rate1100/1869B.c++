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
#include <string>
#include <cstdint>

// ================================================================

ll dist(pair<int, int> a, pair<int, int> b) {
    return (ll)abs(b.second - a.second) + (ll)abs(a.first - b.first);
}

ll solve(vector<pair<int, int > > cord, int k , int a, int b) {
    if(a <= k && b <= k)
        return 0LL;
    ll allDist = dist(cord[a], cord[b]);
    if(k == 0)
        return allDist;

    ll nearestMajorToa = LLONG_MAX, nearestMajorTob = LLONG_MAX;
    for(int i = 1; i <= k; i++) {
        nearestMajorToa = min(nearestMajorToa, dist(cord[a], cord[i]));
        nearestMajorTob = min(nearestMajorTob, dist(cord[b], cord[i]));
    }

    return min(allDist, nearestMajorToa + nearestMajorTob);
}

int main()
{
    smurf;

    int t;
    cin >> t;
    while (t--)
    {
        int n, k, a, b;
        cin >> n >> k >> a >> b;
        vector<pair<int, int> > cordi(n + 1);
        for(int i = 1; i <= n; i++) 
            cin >> cordi[i].first >> cordi[i].second;
        cout << solve(cordi, k, a, b) << el;
    }

    return 0;
}