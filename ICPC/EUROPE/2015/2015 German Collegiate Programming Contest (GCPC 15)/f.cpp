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

namespace PollardRho{
    mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
    const int P = 1e6 + 9;
    ll seq[P];
    int primes[P], spf[P];
    inline ll add_mod(ll x, ll y, ll m){
        return (x += y) < m ? x : x - m;
    }
    inline ll mul_mod(ll x, ll y, ll m){
        ll res = __int128_t(x) * y % m;
        return res;
    }
    inline ll pow_mod(ll x, ll n, ll m){
        ll res = 1;
        for(; n; n >>= 1){
            if(n & 1) res = mul_mod(res, x, m);
            x = mul_mod(x, x, m);
        }
        return res;
    }

    inline bool miller_rabin(ll n){
        if(n <= 2 || (n & 1 ^ 1)) return n == 2;
        if(n < P) return spf[n] == n;
        ll c, d, s = 0, r = n - 1;
        for(; !(r & 1); r >>= 1, s++);

        for(int i = 0; primes[i] < n && primes[i] < 32; ++i){
            c = pow_mod(primes[i], r, n);
            for(int j = 0; j < s; ++j){
                d = mul_mod(c, c, n);
                if(d == 1 && c != 1 && c != n - 1) return 0;
                c = d;
            }
            if(c != 1) return 0;
        }
        return 1;
    }

    void init(){
        int cnt = 0;
        for(int i = 2; i < P; ++i){
            if(!spf[i]) primes[cnt++] = spf[i] = i;
            for(int j = 0, k; (k = i * primes[j]) < P; ++j){
                spf[k] = primes[j];
                if(spf[i] == spf[k]) break;
            }
        }
    }

    ll pollard_rho(ll n){
        while(1){
            ll x = rnd() % n, y = x, c = rnd() % n, u = 1, v, t = 0;
            ll *px = seq, *py = seq;
            while(1){
                *py++ = y = add_mod(mul_mod(y, y, n), c, n);
                *py++ = y = add_mod(mul_mod(y, y, n), c, n);
                if((x = *px++) == y) break;
                v = u;
                u = mul_mod(u, abs(y - x), n);
                if(!u) return __gcd(v, n);
                if(++t == 32){
                    t = 0;
                    if((u = __gcd(u, n)) > 1 && u < n)
                        return u;
                }
            }
            if(t && (u = __gcd(u, n)) > 1 && u < n)
                return u;
        }
    }

    unordered_map<ll, int> factorize(ll n){
        unordered_map<ll, int> res;
        if(n == 1) return res;
        if(miller_rabin(n)){res[n] = 1; return res;}
        while(n > 1 && n < P){
            res[spf[n]]++;
            n /= spf[n];
        }
        if(n >= P){
            ll x = pollard_rho(n);
            res = factorize(x);
            auto o = factorize(n / x);
            for(auto it : o) res[it.fi] += it.se;
        }
        return res;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n; cin >> n;
    PollardRho::init();
    unordered_map<ll, int> primes = PollardRho::factorize(n);
    ll ans = 1;
    for(auto it: primes) ans *= it.se + 1;
    cout << ans << '\n';
}