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

int SG(ll x){
    return (x & 1) ? (x + 1) / 2 % MOD * (x % MOD) % MOD : x / 2 % MOD * ((x + 1) % MOD) % MOD;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n; cin >> n;
    int lim = sqrt(n);
    int ans = n % MOD;
    for(int i = 2; i <= lim; ++i){
        ans += n / i * i % MOD;
        if(ans >= MOD) ans -= MOD;
        ans += 1ll * (SG(n / (i - 1)) - SG(n / i) + MOD) * (i - 1) % MOD;
        if(ans >= MOD) ans -= MOD;
    }
    if(lim < n / lim){
        ans += n / (lim + 1) % MOD * (SG(n / lim) - SG(lim) + MOD) % MOD;
        if(ans >= MOD) ans -= MOD;
    }
    cout << ans << '\n';
}
