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

pair< vi, ll > solve(vector< pair <int, int > >& builds) {
    sort(all(builds), greater<>());
    int n = sz(builds);

    vi res(n + 1);
    ll walking = 0;

    int idxPrev = -1, idxNext = 1;
    res[0] = 0;

    for(int i = 0 ; i < n; i++) {
        res[builds[i].second] = idxNext;
        walking += (2LL * (ll)idxNext * (ll)builds[i].first);

        i++;
        if(i < n) {
            res[builds[i].second] = idxPrev;
            walking += (2LL * (ll)idxNext * (ll)builds[i].first);
        }

        idxPrev--;
        idxNext++;
    }

    return {res, walking};
}

int main() {
    smurf;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n; 

        vector<pair < int , int > > builds(n);
        for(int i = 1; i <= n; i++) {
            cin >> builds[i - 1].first;
            builds[i - 1].second = i;
        }
        
        auto ans = solve(builds);

        cout << ans.second << el;
        for(int i : ans.first)
            cout << i << " ";

        cout << el;
    }
    
    return 0;
}