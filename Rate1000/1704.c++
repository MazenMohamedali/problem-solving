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
class RangeTracker {
private:
    map<ll,ll> m;
public:
    bool rangefun(ll L, ll R) {
        auto it = m.upper_bound(R);
        
        if (it != m.begin()) {
            auto prev = std::prev(it);
            if (prev->second >= L) {
                return true;
            }
        }
        
        m[L] = R;
        return false;
    }
};


int solve(vl& pile, ll x) {
    // RangeTracker* range = new RangeTracker();
    ll minRange = -1,  maxRange = -1;
    int res = 0, n = pile.size();

    for(int i = 0 ; i < n; ++i) {
        ll newMinRange = abs(pile[i] - x);
        ll newMaxRange = abs(pile[i] + x);

        if(minRange == -1 || newMaxRange < minRange || newMinRange > maxRange) {
            res++;
            // range = new RangeTracker();
            // range->rangefun(minRange, maxRange);
            minRange = newMinRange;
            maxRange = newMaxRange;
        } else {
            minRange = max(minRange, newMinRange);
            maxRange = min(maxRange, newMaxRange);
        }
    }

    return res - 1;
}

int main() {
    smurf;

    int t;
    cin >> t;

    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vl pile(n);
        for(ll& i : pile)
            cin >> i;

        cout << solve(pile, x) << el;
    }
    
    return 0;
}