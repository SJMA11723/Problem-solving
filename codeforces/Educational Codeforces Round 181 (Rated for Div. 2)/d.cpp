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

const int MOD = 998244353;

int bin_exp(int a, int b){
    if(!b) return 1;
    int tmp = bin_exp(a, b / 2);
    if(b & 1) return 1ll * tmp * tmp % MOD * a % MOD;
    return 1ll * tmp * tmp % MOD;
}

int inv(int x){
    return bin_exp(x, MOD - 2);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    vvi cub[m + 1];
    int prob[m + 1] = {};
    prob[0] = 1;
    for(int i = 0; i < n; ++i){
        int l, r, p, q;
        cin >> l >> r >> p >> q;
        cub[r].pb({l, p, q});
        prob[0] = 1ll * prob[0] * (q - p + MOD) % MOD * inv(q) % MOD;
    }
    for(int i = 1; i <= m; ++i){
        for(vi info : cub[i]){
            int l = info[0];
            int p = info[1];
            int q = info[2];
            prob[i] += 1ll * prob[l - 1] * p % MOD * inv(q - p + MOD) % MOD;
            if(prob[i] >= MOD) prob[i] -= MOD;
        }
    }
    cout << prob[m] << '\n';
}