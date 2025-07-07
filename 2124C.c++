/*
						  يارب
				اللهم صلي علي سيدنا محمد
==================================================================
					بسم الله الرحمن الرحيم
 
					 الْحَمْدُ لِلَّهِ رَبِّ الْعَالَمِينَ
 
						الرَّحْمَنِ الرَّحِيم
 
						مَالِكِ يَوْمِ الدِّين
 
					إِيَّاكَ نَعْبُدُ وَإِيَّاكَ نَسْتَعِينُ
 
					اهدِنَا الصِّرَاطَ الْمُسْتَقِيمَ
 
		صِرَاطَ الَّذِينَ أَنْعَمْتَ عَلَيْهِمْ غَيْرِ الْمَغْضُوبِ عَلَيْهِمْ وَلاَ الضَّالِّينَ
 
==================================================================
=========================Libraries Block==========================*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<deque>
#include<queue>
#include<list>
#include<forward_list>
#include<stack>
#include<math.h>
#include<cmath>
#include<string>
#include<cstring>
#include<iomanip>
#include<iterator>
#include<array>
#include <stdio.h>
#include<bitset>
#include <numeric>
//#include<bits/stdc++.h>

//=================================================================
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
#define Mazen                    \
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

ll solve(vl& a) {
    int n = a.size();
    ll ans = 1;
    for(int i = 1; i < n; ++i) {
        if(a[i] % a[i - 1] == 0) continue;

        ll x = a[i - 1] / __gcd(a[i], a[i - 1]);
        ans = lcm(x, ans);
    }

    return ans;
}

int main()
{
    Mazen;
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vl v(n);
        for(ll& i : v) cin >> i;
        cout << solve(v) << el;
    }
    
    return 0;
}
