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
const int N = 1e6 + 5, OO = 0x3f3f3f3f; //~1e9
// =================================================================================================================================
// link --> UVA 524 - Prime Ring Problem




bool isPrime(int x) {
    if(x < 2)  return 0;

    for(int i = 2; i*i <= x; i++)    
        if(!(x%i))   return false;

    return true;
}

const int S = 32 + 5;
bool primes[S] {};

vvi ans;
void solve(int len, vi& circle, vb& put) {

    int sz = circle.size();

    if(sz > 1 && !isPrime(circle[sz - 1] + circle[sz - 2]))
        return;

    if(sz == len) {
        if(isPrime(circle[sz - 1] + circle[0]))
            ans.push_back(circle);
        return;
    }

    
    for(int i = 2; i<put.size(); i++) {
        if(!put[i]) {
            circle.push_back(i);
            put[i] = 1;
            solve(len, circle, put);
            circle.pop_back();
            put[i] = 0;
        }
    }
}

int main()
{
    smurf;
    // freopen("inp.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    for(int i = 0; i < S; i++) 
        primes[i] = isPrime(i);

    int n;
    int i = 0;
    while (cin >> n)
    {
        if(i != 0)
            cout << el;
        cout << "Case " << ++i << ":\n";

        vi circle;
        vb put(n + 1);

        circle.push_back(1);
        put[1] = 1;
        solve(n, circle, put);
        
        for(auto& i : ans) {
            for (int j = 0; j < i.size(); ++j) {
                cout << i[j];
                if (j < i.size() - 1)
                    cout << " ";
            }
            cout << el;
        }
        ans.clear();
    }
    return 0;
}