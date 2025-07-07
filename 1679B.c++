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
typedef vector<vl> vvl;
typedef vector<vb> vvb;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef vector<vs> vvs;
const int OO = 0x3f3f3f3f; //~1e9

// ================================================================


void solve(vl& nums, vvl& queries) { 
    map<int, ll> currNums;
    ll sum = 0;
    int n = nums.size(), qn = queries.size();

    for(int i = 1; i <= n; ++i)  {
        sum += nums[i - 1];
        currNums[i] = nums[i - 1]; 
    }

    ll lastVal = -1;
    for(auto q : queries) {
        int op = q[0];
        if (op == 1) {
            int idx = q[1];
            if(currNums.find(idx) == currNums.end()) 
                currNums[idx] = lastVal;
            sum += q[2] - currNums[idx];
            currNums[idx] = q[2];
        } else {
            sum = (ll)n * q[1];
            lastVal = q[1];
            if(!currNums.empty()) currNums.clear();
        }
        
        cout << sum << el;
    }
}


int main() {
    smurf;

    int t = 1;
    while (t--)
    {
        int n, q; 
        cin >> n >> q;
        vl nums(n);
        vvl qnums(q);

        for(auto& i : nums) cin >> i;
        for(auto& i : qnums) {
            ll type;
            cin >> type;
            i.resize(type == 1 ? 3 : 2);
            i[0] = type;
            for (int j = 1; j < (int)i.size(); ++j)   cin >> i[j];
        }

        solve(nums, qnums);
    }
    return 0;
}
