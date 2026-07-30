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

#define MAXN 100'000'000

const int MOD = 1e9 + 7;

vi primes;

void criba(int n){
    vector<bool> no_primo(n + 1);
    no_primo[0] = no_primo[1] = 1;
    for(ll i = 3; i * i <= n; i += 2){
        if(no_primo[i]) continue;
        for(ll j = i * i; j <= n; j += 2 * i)
            no_primo[j] = 1;
    }
    primes.pb(2);
    for(int i = 3; i <= n; i += 2)
        if(!no_primo[i]) primes.pb(i);
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

vi valid_primes;
void find_inv(int k, ll &ans, ll num = 1, int min_p = 0){
    if(k == 1){
        ans = min(ans, num);
        return;
    }

    if(num >= ans) return;

    if(min_p < sz(valid_primes) && valid_primes[min_p] - 1 > k) return;

    if((min_p ? valid_primes[min_p - 1] : 1) < k + 1 && is_prime(k + 1))
        ans = min(ans, num * (k + 1));
    
    for(int i = min_p; i < sz(valid_primes); ++i){
        ll phi = valid_primes[i] - 1;
        ll powp = valid_primes[i];
        while(phi <= k){
            if(k % phi == 0) find_inv(k / phi, ans, num * powp, i + 1);
            phi *= valid_primes[i];
            powp *= valid_primes[i];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;

    criba(sqrt(MAXN + 1) + 1);

    while(t--){
        int k; cin >> k;
        ll ans = LLONG_MAX;
        for(int p : primes){
            if(k % (p - 1) == 0) valid_primes.pb(p);
        }
        find_inv(k, ans);
        cout << (ans == LLONG_MAX ? -1 : ans) << '\n';
        valid_primes.clear();
    }
}