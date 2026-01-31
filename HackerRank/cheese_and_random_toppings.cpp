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

int bin_exp(const int a, int b, const int MOD){
    if(!b) return 1;
    int tmp = bin_exp(a, b / 2, MOD);
    if(b & 1) return 1ll * tmp * tmp % MOD * a % MOD;
    return 1ll * tmp * tmp % MOD;
}

int inv(int x, const int MOD){
    return bin_exp(x % MOD, MOD - 2, MOD);
}

int binom_arr(int n, int k, const int MOD, int fact[]){
    if(k > n || min(n, k) < 0) return 0;
    return fact[n] * inv(fact[k], MOD) * inv(fact[n - k], MOD) % MOD;
}

// teorema de lucas
int binom_lucas(int n, int k, const int MOD){
    if(k > n || min(n, k) < 0) return 0;

    int fact[MOD];
    fact[0] = 1;
    for(int i = 1; i < MOD; ++i) fact[i] = i * fact[i - 1] % MOD;

    int ret = 1;
    while(n){ // log_MOD(n) ~~ 6
        ret *= binom_arr(n % MOD, k % MOD, MOD, fact); // log2(MOD) ~~ 6
        if(ret >= MOD) ret -= MOD;
        n /= MOD;
        k /= MOD;
    }

    return ret;
}

int gcd_ext(int a, int b, int &x, int &y){
    if(!b) return x = 1, y = 0, a;
    int d = gcd_ext(b, a % b, y, x);
    return y -= a / b * x, d;
}

int crt(int a, int m, int b, int n){
    if(n > m) swap(a, b), swap(m, n);
    int x, y, g = gcd_ext(m, n, x, y);
    if((a - b) % g) return -1;
    x = (b - a) % n * x % n / g * m + a;
    return x < 0 ? x + m / g * n : x;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, r, m; cin >> n >> r >> m;

        int m1 = 1, x = 0;
        for(int p = 2; p * p <= m; ++p){
            if(m % p) continue;
            x = crt(x, m1, binom_lucas(n, r, p), p);
            m1 *= p;
            m /= p;
        }
        if(m > 1){
            x = crt(x, m1, binom_lucas(n, r, m), m);
            m1 *= m;
        }
        cout << x % m1 << '\n';
    }
}