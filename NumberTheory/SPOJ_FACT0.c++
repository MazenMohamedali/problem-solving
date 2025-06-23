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
const int N = 1e7 + 5, OO = 0x3f3f3f3f; //~1e9
// ================================================================
// link --> https://www.spoj.com/problems/FACT0/en/

// dont need to solve as string but i try to do that as training, must not fit in timecomplexity
/*


const ll MOD = 1e9 + 7;

bool isDivisor(string n, ll d) {
    int len = n.size();
    ll P10 = 1;
    ll res = 0;
    for(ll i = len - 1; i>= 0; i--) {
        int x = n[i] - '0';
        res+= (x*P10) % d;
        res%=d;
        P10*=10;
        P10%=d;
    }
    return !res;
}   

// this fun GPT
string divide(const string &number, int divisor) {
    string quotient;
    int current = 0;
    
    // Process each digit in the number
    for (char digit : number) {
        current = current * 10 + (digit - '0');
        quotient.push_back((current / divisor) + '0');
        current %= divisor;
    }

    // Remove any leading zeros from the quotient
    size_t pos = quotient.find_first_not_of('0');
    if (pos != string::npos)
        quotient = quotient.substr(pos);
    else
        quotient = "0";  // in case the quotient is 0

    // remainder = current;
    return quotient;
}



string solve(string n) {
    string res = "";
    ll i = 2;
    map<ll, int> frq;
    while (true)
    {
        if(n != "1" && stoll(n) < i * i) { 
            frq[stoll(n)]++;
            break;
        }
        while (isDivisor(n, i))
        {
            i%=MOD;
            frq[i]++;
            n = divide(n, i);
        }
        i++;
        if(n == "1")
            break;
    }
    for(auto& i : frq) {
        res += to_string(i.first) + "^" + to_string(i.second) + ' ';
    }
    return res;
}




*/


map<ll , int> primeFactorization(ll& n) {
    map < ll , int > res;

    while (n % 2 == 0) {
        res[2]++;
        n /= 2;
    }

    for(ll i = 3; i * i <= n; i+=2) {
        while (n % i == 0)
        {
            res[i]++;
            n /= i;
        }
    }
    if(n > 2)
        res[n]++;
    return res;
}

void solve(ll& n) {
    auto factors = primeFactorization(n);

    bool f = 1;
    for(auto i : factors) {
        if(!f)  cout << " ";
        cout << i.first << "^" << i.second;
        f = false;
    }
    cout << el;
}

int main() {
    smurf;
    ll st;
    while (cin >> st && st)
    {
        solve(st);
    }
    return 0;
    
}