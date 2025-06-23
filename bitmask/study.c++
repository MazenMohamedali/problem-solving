#include <bits/stdc++.h>
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
// #define f first
// #define s second
#define MP make_pair
#define el '\n'
#define arrow "---->"
#define smurf    ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL)
typedef long long           ll;
typedef long double         ld;
typedef vector<int>         vi;
typedef vector<double>      vd;
typedef vector<bool>        vb;
typedef vector<long long>  vll;
typedef vector<vi>         vvi;
typedef vector<vd>         vvd;
typedef vector<string>      vs;



// ============================ some sorting =====================
/*
    int n;
    pair< int, int > arr[10];

    //  a, b
    bool cmp(pair< int , int > a, pair< int, int > b) {
        if(a.first < b.first)
            return true;
        if(a.first == b.first)
            return true;
        return false;
    }

    int main() {
        smurf;
        
        cin >> n;
        for(int i = 1; i <= n; i++)
            cin >> arr[i].first >> arr[i].second;
        
        sort(arr + 1, arr + n + 1, cmp);

        for(int i = 1; i <= n; i++)
            cout << arr[i].first << " " << arr[i].second << el;

        return 0;
    }
*/
// ============================  ====================
bool Knowbit(ll n, int i) {
    return (n>>i)&1;
}

ll setBit(ll n, int i) {
    return n|(1LL<<i);
} 

ll resetBit(ll n, int i) {
    return n&(~(1LL<<i));
    // return n&(-1^(1LL<<i));
}

ll flip(ll n, int i) {
    return n^(1LL<<i);
} 


bool isPowerOfTwo(ll n) {
    if(n == 0) return 0;
    return !(n&(n-1));
}

bool isPowerofTwo(int n) {
    for(int i =1; i<=n; i*=2) {
        if(i==n)
        return 1;
    }
    return 0;
}

bool isPowerOfTwo2(ll n) {
    //  __builtin_popcount--> this fun for to count number of 1's bits;
    if(__builtin_popcountl(n) == 1) 
    return 1;
    else return 0;
}

void changeFirstBitTo1(int n) {
    for(int i=0; i<32; i++) {
        if(Knowbit(n, i) == 0) {
            n = setBit(n, i);
            break;
        }
    }
}
// ===================== Marwan ============================
/*
    long long -> ( 64 bit )  (0 -> 63);
    int -> ( 32 bit )  (0 -> 31);
*/
vector <bool> bits;
void MybringBit(ll n) {
    while (n != 0)
    {
        if(n & 1)
            bits.push_back(1);
        else bits.push_back(0);

        n >>= 1;
    }
}

void bringBit(long long x) {
    for(int i = 62; i >= 0; i--) {
        if(x & (1LL << i) ) 
            bits.push_back(1);
        else
            bits.push_back(0);
    }
}


ll power2(ll x) {
    return 1LL << x;
}


const int N = 3; 
vector < int > subsequence[1 << N];
void bitMask(vi& nums) {
    for(ll mask = 1; mask < (1 << N); mask++) {
        for(int i = 0; i < N; ++i) {
            if(mask & (1 << i)) {
                subsequence[mask].push_back(nums[i]);
            }
        }
    }
}



int main() {

/*
    ll x;
    // cin >> x;
    bringBit(x);
    int n = bits.size();

    // for(int i = sz; i >= 0; i--) {
    //     cout << bits[i] << " ";
    // }

    vi nums = {1, 2, 3};
    bitMask(nums);

    for(auto i : subsequence) {
        for(int j : i)
            cout << j << ' ';
        cout << el;
    }
*/
    //                  -==============test fun-==============
    int x = 100110;
    __popcount(x);  // 3 -- > return the number of bits set to 1
    // __ctz(x);       // 1 -- > Returns the count of trailing zeros (the number of 0 bits at the end of x).
    __lg(x);        // 3 -- >  Returns the floor of the log to the base of 2 of x
                    //          which equivalent to the index of the most significant bit.
    
                    

}