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
        ll a, m; cin >> a >> m;
        m /= gcd(a, m);
        ll ans = m;
        for(ll p = 2; p * p <= m; ++p){
            if(m % p) continue;
            while(m % p == 0) m /= p;
            ans -= ans / p;
        }
        if(m > 1) ans -= ans / m;
        cout << ans << '\n';
    }
}
