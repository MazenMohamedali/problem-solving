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
typedef __int128 ull;
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
// ========================================================================================================================

pair<int, int> subSortedArray(vi& a) {
    int n = a.size(), l = 1, r = 1, cur = 1, curl = 1;
    for(int i = 0; i < n; i++) {
        if(i == n || a[i + 1] < a[i]) {
            cur = i + 1;
            if(r - l + 1 < cur - curl + 1) {
                r = cur;
                l = curl;
            }
            curl = i + 2;
        }
    }
    return {l, r};
}   


int main() {
    smurf;
   
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi a1(n), a2(n);
        for(int& i : a1) cin >> i;
        for(int& i : a2) cin >> i;
        auto ans = subSortedArray(a2);
        cout << ans.first << ' ' << ans.second << el;
    }
    
    
    return 0;
}