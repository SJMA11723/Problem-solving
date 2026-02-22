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
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()

const ll MOD = 1e9 + 7;

ll gcd_ext(ll a, ll b, ll &x, ll &y){
    if(!b) return x = 1, y = 0, a;
    ll d = gcd_ext(b, a % b, y, x);
    return y -= a / b * x, d;
}

ll crt(ll a, ll m, ll b, ll n){
    if(n > m) swap(a, b), swap(n, m);
    ll x, y, g = gcd_ext(m, n, x, y);
    x = (b - a) % n * x % n / g * m + a;
    return x < 0 ? x + m * n / g : x;
}

ll bin_exp(int a, int b, int M){
    if(!b) return 1;
    ll tmp = bin_exp(a, b / 2, M);
    if(b & 1) return tmp * tmp % M * a % M;
    return tmp * tmp % M;
}

ll aux_binom(ll n, ll k, ll fact[], ll p){
    if(n < k) return 0;
    return fact[n] * bin_exp(fact[k], p - 2, p) * bin_exp(fact[n - k], p - 2, p) % p;
}

ll binom(int n, int k, int p){
    if(n < k) return 0;

    ll fact[p];
    fact[0] = 1;
    for(int i = 1; i < p; ++i) fact[i] = i * fact[i - 1] % p;

    int res = 1;
    while(n){
        res = res * aux_binom(n % p, k % p, fact, p) % p;
        n /= p;
        k /= p;
    }

    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, r, m; cin >> n >> r >> m;
        vi primes;
        for(int i = 2; i * i <= m; ++i){
            if(m % i) continue;
            primes.pb(i);
            while(m % i == 0) m /= i;
        }
        if(m > 1) primes.pb(m);

        int ans = 0, acc_mod = 1;
        for(int p : primes){
            ans = crt(ans, acc_mod, binom(n, r, p), p);
            acc_mod *= p;
        }
        cout << ans << '\n';
    }
}