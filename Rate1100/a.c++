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
#include <string>
#include <cstdint>
// ========================================================================================================================

int n, m;
int solve(vvi&a, ll maxi) {
    int rowsMaxi = 0, colMaxi = 0, total = 0;


    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) 
        if (a[i][j] == maxi) total++;
    }



    for(int ir = 0, ic = 0; ir < n || ic < m; ir++, ic++) {
        int currnRows = 0, currnCols = 0;
        for(int jr = 0, jc = 0; jr < m || jc < n; jr++, jc++) {
            if(ir < n && jr < m && a[ir][jr] == maxi) currnRows++;
            if(ic < m && jc < n && a[jc][ic] == maxi) currnCols++;
        }   
        if(currnRows > 1) rowsMaxi++;
        if(currnCols > 1) colMaxi++;
    }

    if(rowsMaxi <= 1 && colMaxi <= 1) {
        if(rowsMaxi == 0 && colMaxi == 0 && total > 2)
            return maxi;
        return maxi - 1;
    }

    return maxi;
}


int main() {
    smurf;
    int t;
    cin >> t;

    while (t--)
    {
        cin >> n >> m;
        vvi mat(n, vi(m));
        ll maxi = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> mat[i][j];
                maxi = max(maxi, (ll)mat[i][j]);
            }
        }

        cout << solve(mat, maxi) << el;
    }
    
    return 0;
}