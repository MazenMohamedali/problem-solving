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
// link --> https://codeforces.com/problemset/problem/1385/D


int minMoves = OO;
void a_goodString(string s, char currGood, int moves) {


//                          b b d c a a a a


    if(s.size() == 1) {
        if(s[0] != currGood)    ++moves; 
        minMoves = min(minMoves, moves);
        return;
    }

    int sz = s.size();
    int move1 = moves, move2 = moves;

    string s1 = s.substr(0, sz/2)
    ,      s2 = s.substr(sz/2, sz/2);

    for(int i = 0; i < sz/2; i++) {
        if(s1[i] != currGood) {
            ++move1;
        }
    }
    
    for(int i = 0; i < s2.size(); i++) {
        if(s2[i] != currGood) {
            ++move2;
        }
    }
    a_goodString(s2, currGood+1, move1);
    a_goodString(s1, currGood+1, move2);
}

int main()
{
    smurf;
    // freopen("inp.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int t, n; cin >> t;
    string s;
    while (t--)
    {
        minMoves = OO;
        cin >> n;
        cin >> s;
        a_goodString(s, 'a', 0);
        cout << minMoves << el;
    }
    

    return 0;
}