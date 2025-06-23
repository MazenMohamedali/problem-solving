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
long double abs1 = 1e-9;
int doubleCmp (double a, double b) {
    if(a - b > abs1) 
        return 1;               // a > b
    else if (a-b < -abs1)
        return -1;              //a < b
    else    
        return 0;               // a = b
}
// =================================================================================================================================
// link --> https://codeforces.com/problemset/problem/476/B

int senderMessage;
int trueMessage = 0;
int allMessages = 0;
void solveHelper(string s, int i, int sum) {
    if(i == s.size()) {
        if(sum == senderMessage)
            ++trueMessage;
        ++allMessages;
        return;
    }
    

    if(s[i] == '+') solveHelper(s, i+1, sum + 1);
    else if(s[i] == '-') solveHelper(s, i+1, sum - 1);
    else {
        solveHelper(s, i+1, sum + 1);
        solveHelper(s, i+1, sum - 1);
    }
}


double solve(string& a, string& b){
    senderMessage = 0;
    for(char i : a) 
        i == '+' ? ++senderMessage : --senderMessage;
    
    solveHelper(b, 0, 0);
    return trueMessage/(double)(allMessages);
}

int main()
{
    smurf;
    // freopen("inp.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    string s1, s2;
    cin >> s1 >> s2;

    printf("%.12lf", solve(s1, s2));
    return 0;
}