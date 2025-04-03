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
//UVA 10344 - 23 out of 5


bool solve(const vi& n, ll sum, int i) {
    if(i == n.size()) {
        if(sum == 23) return true;
        return false;
    }
    return solve(n, sum + n[i], i+1) || solve(n, sum * n[i], i+1) || solve(n, sum - n[i], i+1);
}

set<vi> alter;
void solveAlter(vi t, vi& res, vb& taked) {
    if(res.size() == t.size()) {
        alter.insert(res);
        return;
    }
    for(int i = 0; i<t.size(); i++) {
        if(!taked[i]) {
            taked[i] = 1;
            res.push_back(t[i]);
            solveAlter(t, res, taked);
            res.pop_back();
            taked[i] = 0;
        }
    }
}

int main() {
    // freopen("inp.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    vi val(5);
    while (cin >> val[0] >> val[1]  >> val[2]  >> val[3]  >> val[4] , val[0]||val[1]||val[2]||val[3]||val[4])
    {
        bool finalRes = false;
        vi res; 
        vb taked(val.size(), false);
        alter.clear();
        solveAlter(val, res, taked);
        for(auto& alt : alter){
            finalRes = solve(alt, alt[0], 1);
            if(finalRes)   break;
        }
        cout << (finalRes ? "Possible" : "Impossible") << el;
    }
    return 0;
}