/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()

const int MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        ll res = 0;
        int ans; cin >> ans; cout << ans << ' ';
        for(int i = 1; i < n; ++i){
            int ai; cin >> ai;
            if(ai >= ans) res += ai - ans;
            else if(ai + res >= ans){
                res -= ans - ai;
            } else {
                ai += res;
                res = 0;

                int k = (ans - ai + i) / (i + 1);
                ans -= k;
                res = 1ll * k * i;
                res -= ans - ai;
            }
            cout << ans << " \n"[i + 1 == n];
        }
    }
}