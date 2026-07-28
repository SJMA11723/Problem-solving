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
#define MAXN 1000000

const int MOD = 1e9 + 7;

vi divs[MAXN + 1];
vi primes[MAXN + 1];
int cnt[MAXN + 1];
int new_sets[MAXN + 1];
int fact[MAXN + 1];
int inv_fact[MAXN + 1];

int combi(int n, int k){
    if(n < k || k < 0) return 0;
    return 1ll * fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fact[0] = 1;
    for(int i = 1; i <= MAXN; ++i){
        fact[i] = 1ll * i * fact[i - 1] % MOD;
        for(int j = i; j <= MAXN; j += i)
            divs[j].pb(i);
        if(i > 1 && sz(divs[i]) == 2)
        for(int j = i; j <= MAXN; j += i)
            primes[j].pb(i);
    }
    inv_fact[MAXN] = 397802501;
    for(int i = MAXN; 0 < i; --i) inv_fact[i - 1] = 1ll * i * inv_fact[i] % MOD;
    
    int n, k, q; cin >> n >> k >> q;
    for(int i = 0; i < n; ++i){
        int ai; cin >> ai;
        for(int d : divs[ai]) cnt[d]++;
    }

    int ans = 0;
    for(int i = MAXN; 0 < i; --i){
        new_sets[i] = combi(cnt[i], k);
        for(int j = 2 * i; j <= MAXN; j += i){
            new_sets[i] += MOD - new_sets[j];
            if(new_sets[i] >= MOD) new_sets[i] -= MOD;
        }
        
        ans += 1ll * new_sets[i] * i % MOD;
        if(ans >= MOD) ans -= MOD;
    }

    while(q--){
        int cj; cin >> cj;
        for(int d : divs[cj]) new_sets[d] = combi(cnt[d], k - 1);
        for(int p : primes[cj]){
            for(int d : divs[cj]){
                if(d % p) continue;
                new_sets[d / p] += MOD - new_sets[d];
                if(new_sets[d / p] >= MOD) new_sets[d / p] -= MOD;
            }
        }
        for(int d : divs[cj]){
            ans += 1ll * new_sets[d] * d % MOD;
            if(ans >= MOD) ans -= MOD;
            cnt[d]++;
        }

        cout << ans << '\n';
    }
}
