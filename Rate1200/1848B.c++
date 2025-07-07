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


int solve(map<int, vi>& nums, int sz) { 
    int ans = sz; 
    for(auto& [num, idxs] : nums) {

        idxs.insert(idxs.begin(), -1);
        idxs.push_back(sz);

        int maxDist = 0, secondMaxDist = 0;
        int curn = idxs.size();
        
        for(int i = 1; i < curn; i++) {
            
            int currDist = idxs[i] - idxs[i - 1] - 1;
            
            if(currDist > maxDist) {
                secondMaxDist = maxDist;
                maxDist = currDist;
            } else if(currDist > secondMaxDist) 
                secondMaxDist = currDist;
        }
        ans = min(ans, max(maxDist / 2, secondMaxDist));
    }
    return ans;
}


int main() {
    smurf;

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        map<int, vi> nums;
        int x;
        for(int i = 0; i < n; ++i) {
            cin >> x;
            nums[x].push_back(i);
        }
        cout << solve(nums, n) << el;
    }
    return 0;
}
