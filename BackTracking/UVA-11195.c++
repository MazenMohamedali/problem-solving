
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
const int N = 1e6 + 5, OO = 0x3f3f3f3f; //~1e9
// ================================================================
// link --> UVA - 11195 Another n-Queen Problem  
// ---------------------------Time limit !:)------------------


int n;  // size for grid

bool inRange(int r, int c) {
    return r >= 0 && c >= 0 && r < n && c < n;
}

bool validCeil(vvi& grid, int r, int c) {
    if(!inRange(r, c) || grid[r][c] == -1)
        return false;

    for(int i = c - 1; i >= 0; --i) {
        if(grid[r][i] == 1)
            return false;
    }

    for(int i = r - 1; i >= 0; --i) {
        if(grid[i][c] == -1)    
            break;
        if(grid[i][c] == 1)
            return false;
    }

    for(int i = r - 1, j = c - 1; i >= 0 && j >= 0; --i, --j) {
        if(grid[i][j] == -1)    
            break;
        if(grid[i][j] == 1)
            return false;
    }

    
    for(int i = r + 1, j = c - 1; i < n && j >= 0; ++i, --j) {
        if(grid[i][j] == -1)    
            break;
        if(grid[i][j] == 1)
            return false;
    }

    return true;
}

int validSolutionCntr = 0;
void solve(vvi& grid, int curCol) {
    if(curCol >= n) {
        ++validSolutionCntr;
        return;
    }
    

    for(int i = 0; i < n; i++) {
        if(grid[i][curCol] == 0 && validCeil(grid, i, curCol)) {
            grid[i][curCol] = 1;
            solve(grid, curCol + 1);
            grid[i][curCol] = 0;
        } 
    }
}


int main() {
    smurf;
    freopen("inp.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int nCase = 0;
    while (cin >> n && n)
    {
        vvi grid(n, vi(n, 0));

        char c;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> c;
                if(c == '*')    grid[i][j] = -1;
            }
        }

        solve(grid, 0);
        cout << "Case " << ++nCase << ": " << validSolutionCntr << el;
        grid.clear();
        validSolutionCntr = 0;
    }
    
    

    return 0;
}