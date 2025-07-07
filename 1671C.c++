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

vl nums;
ll solve(ll n, ll target, ll ans, ll sum, ll daysSoFar)
{
    if (n == 0) return ans;
    if (sum > target)
    {
        sum -= nums[n - 1];
        return solve(n - 1, target, ans, sum, daysSoFar);
    }

    int s = 1, e = 1e9 + 5, mid;
    int days = 0;
    while (s <= e)
    {
        mid = s + (e - s) / 2;
        ll t = sum + ll(n) * (mid - 1);
        if (t <= target)
        {
            days = mid;
            s = mid + 1;
        }
        else
            e = mid - 1;
    }

    ans += (ll)n * days;
    daysSoFar += days;
    sum += ((ll)n * (ll)days) - (ll)(nums[n - 1] + daysSoFar);
    return solve(n - 1, target, ans, sum, daysSoFar);
}

int main()
{
    smurf;

    int t;
    cin >> t;
    while (t--)
    {
        int n, target;
        cin >> n >> target;
        nums.resize(n);
        ll summation = 0;
        for (ll &i : nums)
        {
            cin >> i;
            summation += i;
        }
        sort(nums.begin(), nums.end());
        cout << solve(n, target, 0, summation, 0) << el;
    }
    return 0;
}
