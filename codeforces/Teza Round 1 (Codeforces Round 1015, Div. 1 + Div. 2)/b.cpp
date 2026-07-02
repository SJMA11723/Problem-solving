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
        map<ll, int> cnt;
        for(int i = 0; i < n; ++i){
            ll x; cin >> x;
            cnt[x]++;
        }
        ll mini = cnt.begin()->fi;
        bool ok = cnt.begin()->se > 1;
        if(!ok){
            ll g = 0;
            for(auto it : cnt) if(it.fi % mini == 0 && it.fi != mini) g = gcd(g, it.fi);
            ok = g == mini;
        }
        cout << (ok ? "Yes\n" : "No\n");
    }
}
