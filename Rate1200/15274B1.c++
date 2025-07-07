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


string solve(string s) {
    
    int n = s.size();
    bool aliceBob = 1;
    bool canReverseAli = 1;
    bool canReverseBob = 1;
    bool isBalindrom = 1;

    int cntZero = 0;
    for(auto i : s) if(i == '0') cntZero++;

    if(cntZero == 0) return "DRAW";

    int aliCost = 0, bobCost = 0;
    if(cntZero % 2 != 0 && s[n / 2] == '0') {
        aliCost++;
        aliceBob = 0;
        cntZero--;
    }


    while (cntZero)
    {
        if(isBalindrom) {
            if(aliceBob) {
                aliCost++;
                aliceBob = 0;
            }
            else {
                bobCost++;
                aliceBob = 1;
            }
            isBalindrom = 0;
            cntZero--;
        } else {
            if(aliceBob) {
                if(canReverseAli) {
                    canReverseAli = 0;
                } else {
                    canReverseAli = 1;
                    aliCost++;
                    cntZero--;
                }
                aliceBob = 0;
            } else {
                if(canReverseBob) {
                    canReverseBob = 0;
                } else {
                    canReverseBob = 1;
                    bobCost++;
                    cntZero--;
                }
                aliceBob = 1;
            }

            isBalindrom = 1;
        }
    }

    return aliCost == bobCost ? "DRAW" :
           aliCost > bobCost ? "BOB" : "ALICE";
}   

int main()
{
    smurf;

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string pal;
        pal.reserve(n);
        cin >> pal;
        cout << solve(pal) << el;
    }
    return 0;
}