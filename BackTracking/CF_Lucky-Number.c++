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
#define f first
#define s second
#define MP make_pair
#define el '\n'
#define arrow "---->"
#define smurf ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

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
// =================================================================================================================================
//https://codeforces.com/problemset/problem/96/B

vl nums;

void solve(string st, int f4, int s7, int len) {
        if(st.size() == len) {
            if(f4 == s7) nums.push_back(stoll(st));
            return;
        }
        solve(st + '4', f4 + 1, s7, len);
        solve(st + '7', f4, s7 + 1, len);
}   

int main() {
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ll n;   cin >> n;
    int sz = to_string(n).size();

    if(sz%2==0) {
        solve("", 0, 0, sz);
        solve("", 0, 0, sz + 2);
    } else  solve("", 0, 0, sz + 1);


    sort(all(nums));
    for(ll i : nums) {
        if(i >= n)  return cout << i << el, 0;
    }
}