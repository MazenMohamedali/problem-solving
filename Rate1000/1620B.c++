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

ll TriangelArea(vl& s1, vl& s2, vl& s3, vl& s4, ll w, ll h) {
    sort(all(s1), greater<ll>());
    sort(all(s2), greater<ll>());
    sort(all(s3), greater<ll>());
    sort(all(s4), greater<ll>());

    int n1 = s1.size(), n2 = s2.size(), n3 = s3.size(), n4 = s4.size();

    ll area = (s1[0] - s1[n1 - 1]) * h;
    area = max(area, (ll)(s2[0] - s2[n2 - 1]) * h);
    area = max(area, (ll)(s3[0] - s3[n3 - 1]) * w);
    area = max(area, (ll)(s4[0] - s4[n4 - 1]) * w);

    return area;
}

int main() {
    smurf;
    int t;
    cin >> t;
    while (t--)
    {
        ll h, w;
        cin >> w >> h;
        
        vector<vl> sides(4);

        int n;
        for(int i = 0; i < 4; i++) {
            cin >> n;
            sides[i].resize(n);
            for(ll& i : sides[i])
                cin >> i;
        }

        cout << TriangelArea(sides[0], sides[1], sides[2], sides[3], w, h) << el;
    }
    
    return 0;
}