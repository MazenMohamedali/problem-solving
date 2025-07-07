/*================================================================
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

vector<pair<int,int>> solve(vector<pair<int,int>>& xIdx) {
    vector<pair<int,int>> ans, notValid{{-1,-1}};
    sort(all(xIdx));
    int n = xIdx.size();

    if (xIdx[0].first == xIdx[n-1].first)
        return notValid;

    int p = 1;
    while (xIdx[p].first == xIdx[0].first) 
        ++p;

    for (int i = 1; i < n; ++i) {
        if (xIdx[i].first != xIdx[0].first)
            ans.emplace_back(xIdx[0].second, xIdx[i].second);
        else
            ans.emplace_back(xIdx[p].second, xIdx[i].second);
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
        int n; cin >> n;
        vector< pair <int, int > > nums(n);
        for(int i = 0; i < n; i++) {    
            cin >> nums[i].first;
            nums[i].second = i + 1;
        }

        auto ans = solve(nums);
        if(ans[0].first == -1) cout << "NO" << el;
        else {
            cout << "YES" << el;
            for(auto [x, y] : ans) cout << x << ' ' << y << el;
        }
        
        
    }
    
    return 0;
}
