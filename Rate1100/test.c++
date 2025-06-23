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
vl quests(vl &a) {
    int n = a.size();
    vl b = a;
    sort(all(b));
    
    // Create prefix sum array
    vl prefix(n);
    prefix[0] = b[0];
    for(int i = 1; i < n; i++) {
        prefix[i] = prefix[i-1] + b[i];
    }
    
    vl ans(n);
    for(int i = 0; i < n; i++) {
        // Find the rightmost position where b[j] <= a[i]
        int pos = upper_bound(all(b), a[i]) - b.begin() - 1;
        
        if(pos < 0) {
            ans[i] = 0;
            continue;
        }
        
        ll cumSum = prefix[pos];
        
        // Find how many elements we can remove with cumSum
        int removable = upper_bound(all(prefix), cumSum) - prefix.begin();
        
        ans[i] = removable;
    }
    return ans;
}

int main()
{
    smurf;
    int t;
    cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vl a(n);
        for (ll &i : a)
            cin >> i;
        vl ans = quests(a);
        for(ll i : ans)
            cout << i << ' ';
        cout << el;
    }
    return 0;
}

/*
1
4 1 1 4 2

*/