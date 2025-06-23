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
// link --> https://leetcode.com/problems/palindrome-partitioning/description/
class Solution {
    private:
        string t;
        int n;
        vs cur;

        bool isPalindrome(const string &s) {
            int len = s.size();
            for(int i = 0; i < len/2; ++i) {
                if(s[i] != s[len - i - 1])  
                    return false;
            }
            return true;
        }
        void solve(int st, vvs& ans) {

            if(st == t.size()) {
                ans.push_back(cur);
                // cur.clear();
            }

            for(int i = st; i < n; ++i) {
                string left = t.substr(st, i - st + 1);
                if(isPalindrome(left)) {
                    cur.push_back(left);
                    solve(i + 1, ans);
                    cur.pop_back();
                }
            }
        }
    public:
        vector<vector<string>> partition(string s) {
            vvs ans;
            t = s;
            n = (int)t.size();
            solve(0, ans);
            return ans;
        }
    };

int main()
{
    smurf;
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}