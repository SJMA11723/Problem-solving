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

vi primes;

void criba(int n, int k){
    vector<bool> no_primo(n + 1);
    no_primo[0] = no_primo[1] = 1;
    for(ll i = 3; i * i <= n; i += 2){
        if(no_primo[i]) continue;
        for(ll j = i * i; j <= n; j += 2 * i)
            no_primo[j] = 1;
    }
    primes.pb(2);
    for(int i = 3; i <= n; i += 2)
        if(!no_primo[i] && k % (i - 1) == 0) primes.pb(i);
}

bool is_prime(int n){
    if(n < 2) return 0;
    if(n == 2) return 1;
    if(n % 2 == 0) return 0;
    if(binary_search(all(primes), n)) return 1;
    for(ll d = 3; d * d <= n; d += 2) if(n % d == 0)
        return 0;
    return 1;
}

void find_inv(int k, ll &ans, ll num = 1, int min_p = 0){
    if(k == 1){
        ans = min(ans, num);
        return;
    }

    if(num >= ans) return;

    if(min_p < sz(primes) && primes[min_p] - 1 > k) return;

    if((min_p ? primes[min_p - 1] : 1) < k + 1 && is_prime(k + 1))
        ans = min(ans, num * (k + 1));
    
    for(int i = min_p; i < sz(primes); ++i){
        ll phi = primes[i] - 1;
        ll powp = primes[i];
        while(phi <= k){
            if(k % phi == 0) find_inv(k / phi, ans, num * powp, i + 1);
            phi *= primes[i];
            powp *= primes[i];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k; cin >> k;
    criba(sqrt(k + 1) + 1, k);
    ll ans = LLONG_MAX;
    find_inv(k, ans);
    cout << (ans == LLONG_MAX ? 0 : ans) << '\n';
}