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
const int OO = 0x3f3f3f3f; //~1e9


//          --> number theory helper  <--
const int MOD = 1e9 + 7;
ll add(ll a, ll b) { return ((a % MOD) + (b % MOD)) % MOD; }
ll sub(ll a, ll b) { return (((a - b) % MOD) + MOD) % MOD; }
ll mul(ll a, ll b) { return ((a % MOD) * (b % MOD)) % MOD; }
ll power(ll b, ll e) {
    if(e == 0) return 1;
    ll h = power(b, e/2);
    if(!(e & 1)) return mul(h, h);
    return mul(mul(b , h), h);
}
ll divide(ll a, ll b) { return mul(a, power(b, MOD - 2)); }


// miller-Rabin primality test
bool isPrime(ll n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    for (ll i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}


vl divisors(ll n) {
    vl divisors;
    for(ll i = 1; i*i <= n; i++) {
        if(n % i == 0) {
            divisors.push_back(i);
            if(i != n / i)
                divisors.push_back(n / i);
        }
    }

    sort(all(divisors));
    return divisors;
}



// map<int , int> primeFactorization(ll n) {
//     map < int , int > res;
//     for(int i = 2; i < N; i++) {
//         int k, v = 0;
//         if(isPrimes[i]) {
//             k = i;
//             while (n % isPrimes[i])
//             {
//                 ++v;
//                 n /= isPrimes[i];
//             }
//             if(v > 0) {
//                 res.insert(k, v);
//                 v = 0;
//             }
//         }
//     }
//     if(n != 1)
//         res[n]++;
//     return res;
// }

 
// ================================================================
// link --> 

// time limit
/*
    const int N = 1e5 + 5;
    vi isPrimes(N, 1);

    void seive() {
        isPrimes[0] = isPrimes[1] = 0;

        for(int i = 2; i * i < N; i++) {
            if(isPrimes[i]) {
                for(int j = i * i;  j <= N; j+=i) 
                    isPrimes[j] = 0;
            }
        }
    }


    void coprime2(vi& nums, int m) {
        int n = nums.size();
        for(int i : nums) 
            isPrimes[i] = 0;
        

        vi validPrimes;
        for(int i = 2; i <= m; i++) {
            if(isPrimes[i] == 1) 
                validPrimes.push_back(i);
        }

        set<int>res;
        res.insert(1);
        bool flag = 1;
        for(int i : validPrimes) {
            for(int j : nums) {
                if(__gcd(i, j) != 1) {
                    flag = 0;
                    break;
                }
            }
            if(flag)
                res.insert(i);
            flag = 1;
        }

        cout << res.size() << el;
        for(auto i : res) 
            cout << i << el;
    }


    int main() {
        smurf;
        int n, m;
        cin >> n >> m;

        vi nums(n);
        for(int& i : nums)
            cin >> i;
        
        coprime2(nums, m);

        return 0;
    }
*/

const int N = 1e5 + 3;

vi spf(N, 1);
void SPF() {
    for(int i = 2; i <= N; ++i)  spf[i] = i;

    for(int i = 2; i * i <= N; ++i) {
        if(spf[i] == 0)
    }
}

vb valid(N, 1);
void primeFactros(const vi& nums, int m) {
        valid.assign(m + 1, 1);
        for(int i : nums) {
            while (i > 1)
            {
                int spfI = spf[i];
                for(int j = spfI; j <= m; j += spfI)
                    valid[j] = 0;
                while(i % spfI == 0) i /= spfI;
            }
            
        }
}

vi ans(int m) {
    vi ans;
    for(int i = 1; i <= m; i++) {
        if(valid[i])
            ans.push_back(i);
    }
    return ans;
}

int main() {
    smurf;

    int n, m;
    cin >> n >> m;

    vi nums(n);
    for(int& i : nums)  cin >> i;

    SPF();
    primeFactros(nums, m);
    vi res = ans(m);

    cout << res.size() << el;
    for(int x : res)
        cout << x << el;


    return 0;
}