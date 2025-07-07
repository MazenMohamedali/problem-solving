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


pair<int, int> solve(vi& nums) { 
    auto ans = {-1, -1};
    int n = nums.size();

    set<int> MiniMaxInRange;
    for(int i = 0; i < n; i++) MiniMaxInRange.insert(nums[i]);

    int i = 0, j = n - 1;
    while (i < j)
    {
        int mini = *MiniMaxInRange.begin();
        int maxi = *MiniMaxInRange.rbegin();
        if( nums[i] == mini || nums[i] == maxi ||
            nums[j] == mini || nums[j] == maxi ) {
            if(nums[i] == mini || nums[i] == maxi) {
                nums[i] == mini ? MiniMaxInRange.erase(mini) : MiniMaxInRange.erase(maxi);
                i++;
            } 
            
            if(nums[j] == mini || nums[j] == maxi) {
                nums[j] == mini ? MiniMaxInRange.erase(mini) : MiniMaxInRange.erase(maxi);
                j--;
            } 
        } 
        else 
            return {i + 1, j + 1};
    }
    
    return {-1, -1};
}


int main() {
    smurf;

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi nums(n);
        for(int& i : nums) cin >> i;
        auto[f, s] = solve(nums);
        if(f == -1) cout << -1;
        else cout << f << ' ' << s;
        cout << el;
    }
    return 0;
}
