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
#define MAXN 31623

const int MOD = 1e9 + 7;

vi primes;
vector<bool> no_prime(MAXN + 1);

bool is_prime(int x){
    if(x <= MAXN) return !no_prime[x];
    for(int p : primes){
        if(p * p > x) break;
        if(x % p == 0) return 0;
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    no_prime[0] = no_prime[1] = 1;
    for(int i = 2; i <= MAXN; ++i) if(!no_prime[i]){
        primes.pb(i);
        for(int j = 2 * i; j <= MAXN; j += i) no_prime[j] = 1;
    }

    int n, q; cin >> n >> q;
    int ans[n + 1]; ans[0] = 0;
    for(int i = 1; i <= n; ++i){
        int x; cin >> x;
        int phi = x;
        for(int p : primes){
            if(p * p > x) break;
            if(x % p) continue;
            while(x % p == 0) x /= p;
            phi -= phi / p;
        }
        if(x > 1) phi -= phi / x;
        ans[i] = is_prime(phi);
    }
    for(int i = 1; i <= n; ++i) ans[i] += ans[i - 1];

    while(q--){
        int l, r; cin >> l >> r;
        cout << ans[r] - ans[l - 1] << '\n';
    }
}