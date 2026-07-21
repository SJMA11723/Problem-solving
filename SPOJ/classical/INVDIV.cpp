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

#define MAXP 40'000

const int MOD = 1e9 + 7;

vi primes;

void criba(int n){
    primes.clear();
    if(n < 2) return;
    vector<bool> no_prime(n + 1);
    no_prime[0] = no_prime[1] = 1;
    for(int i = 3; i * i <= n; i += 2){
        if(no_prime[i]) continue;
        for(int j = i * i; j <= n; j += 2 * i)
            no_prime[j] = 1;
    }

    primes.pb(2);
    for(int i = 3; i <= n; i += 2) if(!no_prime[i])
        primes.pb(i);
}

bool is_prime(int x){
    if(x < 2) return 0;
    for(int p : primes){
        if(1ll * p * p > x) break;
        if(x % p == 0) return 0;
    }
    return 1;
}

ll find_inv(int n, int min_prime = 0, ll num = 1){
    if(n == 1) return num;
    if(min_prime >= sz(primes)) return LLONG_MAX;
    if(primes[min_prime] > n) return LLONG_MAX;

    ll res = LLONG_MAX;

    if(primes[min_prime] <= n - 1 && is_prime(n - 1)) res = min(res, num * (n - 1));

    for(int i = min_prime; i < sz(primes) && 1ll * primes[i] * primes[i] <= n; ++i){
        ll sum = primes[i] + 1, powp = primes[i];
        while(sum <= n){
            if(n % sum == 0) res = min(res, find_inv(n / sum, i + 1, num * powp));
            powp *= primes[i];
            sum += powp;
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    criba(MAXP);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        ll ans = find_inv(n);
        cout << (ans == LLONG_MAX ? -1 : ans) << '\n';
    }
}