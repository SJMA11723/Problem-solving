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

void factorize(ll n, vll &primes){
    for(ll i = 2; i * i <= n; ++i){
        if(n % i) continue;
        while(n % i == 0) n /= i;
        primes.pb(i);
    }
    if(n > 1) primes.pb(n);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    for(int tt = 1; tt <= t; ++tt){
        cout << "Case " << tt << '\n';
        
        ll n; cin >> n;
        int q; cin >> q;
        vll primes;
        factorize(n, primes);

        map<ll, ll> revphi;
        for(ll d = 1; d * d <= n; ++d){
            if(n % d) continue;
            ll phival = d;
            for(ll p : primes){
                if(p > d) break;
                if(d % p) continue;
                phival -= phival / p;
            }
            revphi[n / d] = phival;
            
            if(d * d != n){
                ll div = n / d;
                phival = div;
                for(ll p : primes){
                    if(p > div) break;
                    if(div % p) continue;
                    phival -= phival / p;
                }
                revphi[d] = phival;
            }
        }

        revphi[0] = 0;
        ll sum = 0;
        for(auto &it : revphi) it.se = sum += it.se;

        while(q--){
            ll x; cin >> x;
            if(x < 0) cout << "0\n";
            else {
                auto it = revphi.upper_bound(x);
                it--;
                cout << it->se << '\n';
            }
        }
    }
}