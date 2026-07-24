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
#define MAXN 10000000

const int MOD = 1e9 + 7;

int fact[MAXN + 1];
vector<int> primes(MAXN + 1, 1);

int bin_exp(int a, int b){
    if(!b) return 1;
    int tmp = bin_exp(a, b / 2);
    if(b & 1) return 1ll * tmp * tmp % MOD * a % MOD;
    return 1ll * tmp * tmp % MOD;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fact[0] = 1;
    for(int i = 1; i <= MAXN; ++i) fact[i] = 1ll * i * fact[i - 1] % (MOD - 1);
    primes[0] = primes[1] = 0;
    for(ll i = 2; i <= MAXN; ++i){
        if(primes[i]) for(ll j = i * i; j <= MAXN; j += i) primes[j] = 0;
        primes[i] += primes[i - 1];
    }

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int phi = n, cnt_primes = primes[n];
        for(int d = 2; d * d <= n; ++d){
            if(n % d) continue;
            while(n % d == 0) n /= d;
            phi -= phi / d;
        }
        if(n > 1) phi -= phi / n;

        cout << bin_exp(phi, fact[max(0, cnt_primes - phi)]) << '\n';
    }
}