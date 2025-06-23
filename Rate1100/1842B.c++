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
typedef __int128 ull;
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

bool isBinA(int a, int b) {
    for(int i = 0; i <= 32; i++) {
        if(b & (1 << i) && !(a & (1 << i))) return false;
    }
    return true;
}

bool solve(int x, vi& n1, vi& n2, vi& n3) {
    bool isBlocked1 = 0, isBlocked2 = 0, isBlocked3 = 0;
    int knowledge = 0;
    int n = n1.size();
    for(int i = 0; i < n; i++) {
        if(knowledge == x) return true;
        if(isBlocked1 && isBlocked2 && isBlocked3) return false;

        if(!isBlocked1) {
            isBinA(x, n1[i]) ?
                knowledge |= n1[i] : isBlocked1 = true;
        } 

        if(!isBlocked2) {
            isBinA(x, n2[i]) ?
                knowledge |= n2[i] : isBlocked2 = true;
        } 

        if(!isBlocked3) {
            isBinA(x, n3[i]) ?
                knowledge |= n3[i] : isBlocked3 = true;
        } 
    }

    return knowledge == x;
}

void readvi(vi& a) {
    for(int& i : a) cin >> i;
}


int main() {
    smurf;
    int t;
    cin >> t;

    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vi n1(n), n2(n), n3(n);
        readvi(n1);
        readvi(n2);
        readvi(n3);
        cout << (solve(x, n1, n2, n3) ? "YES" : "NO") << el;
    }
    
    return 0;
}