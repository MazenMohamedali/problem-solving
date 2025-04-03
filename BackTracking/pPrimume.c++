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
const int N = 2e5 + 10, OO = 0x3f3f3f3f;

// =================================================================================================================================
//UVA 10344 - 23 out of 5
const int N = 2e5 + 10, OO = 0x3f3f3f3f;


int val[N];

bool F(int idx, int value) {

    if(idx == 5)    {
        if(value == 23) return 1;
        return 0;
    }

    return F(idx + 1, value + val[idx]) || F(idx + 1, value - val[idx]) || F(idx + 1, value * val[idx]);
}

int main() {
    // comma operator execute left hand side then check for right hand side
    // freopen("inp.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    while (cin >> val[0] >> val[1]  >> val[2]  >> val[3]  >> val[4] , val[0]||val[1]||val[2]||val[3]||val[4])
    {
        bool res = 0;
        sort(val, val + 5);
        do {
            if(F(1, val[0]))    res = 1;
        }while(next_permutation(val, val + 5));
        cout << (res ? "Possible" : "Impossible") << el;
    }
}