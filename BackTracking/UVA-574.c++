#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
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
#define sortD(v)    sort(all(v), greater<int>())

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
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef vector<vs> vvs;
const int N = 2e5 + 10, OO = 0x3f3f3f3f; //~1e9
// =================================================================================================================================
// link --> https://vjudge.net/problem/UVA-11332

bool outFormat(const vi &a, const vi &b) {
    int n = min(a.size(), b.size());
    for (int i = 0; i < n; i++) {
        if(a[i] != b[i])
            return a[i] > b[i];
    }
    return a.size() > b.size();
}


vvi  finalRes;
void solve(vi& nums, int t, int sum, int i, vi& curRes) {
    
    if(sum > t || i==nums.size())     return;

    if(sum == t) {
        sortD(curRes);
        finalRes.push_back(curRes);
        return;
    } 

    solve(nums, t, sum, i + 1, curRes);
    curRes.push_back(nums[i]);
    solve(nums, t, sum+nums[i], i + 1, curRes);
    curRes.pop_back();
}   


int main()
{
    smurf;
    freopen("inp.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    ll t, n;
    while (cin >> t >> n, t && n)
    {
        finalRes.clear();
        vi nums(n);
        for(auto &i : nums) cin >> i;

        vi curRes;
        solve(nums, t, 0, 0, curRes);

        sort(finalRes.begin(), finalRes.end(), outFormat);
        finalRes.erase(unique(finalRes.begin(), finalRes.end()), finalRes.end());

        cout << "Sums of " << t << ":\n";
        if(finalRes.empty()) {
            cout << "NONE" << el;
        } else {
            for(auto& i : finalRes) {
                for(int j = 0; j < i.size(); j++) {
                    cout << i[j];
                    if(j!= i.size() - 1)
                        cout << "+";
                }
                cout << el;
            }
        }
    }
    return 0;
}