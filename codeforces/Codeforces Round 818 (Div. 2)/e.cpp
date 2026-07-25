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
    int n; cin >> n;
    vi divs[n + 1];
    int phi[n + 1]; phi[0] = 0; phi[1] = 1;
    iota(phi + 2, phi + n + 1, 1);
    for(int i = 2; i <= n; ++i){
        for(int j = 2 * i; j <= n; j += i){
            divs[j].pb(i);
            phi[j] -= phi[i];
        }
    }

    int ans = 0;
    for(ll c = 1; c + 2 <= n; ++c){
        ans += c * phi[n - c] % MOD;
        if(ans >= MOD) ans -= MOD;
        
        for(int d : divs[n - c]){
            ans += 1ll * lcm(c, d) * phi[(n - c) / d] % MOD;
            if(ans >= MOD) ans -= MOD;
        }
    }
    cout << ans << '\n';
}