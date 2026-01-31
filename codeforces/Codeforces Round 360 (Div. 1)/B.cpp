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

void criba(int n, vi &lp){
    lp.clear();
    if(n < 2) return;
    lp.resize(n + 1);
    for(int i = 2; i <= n; i += 2) lp[i] = 2;
    for(ll i = 3; i <= n; i += 2){
        if(lp[i]) continue;
        lp[i] = i;
        for(ll j = i * i; j <= n; j += 2 * i)
            lp[j] = i;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vi lp;
    criba(1e6, lp);
    int n, k; cin >> n >> k;
    ll l = 1;

    map<int, int> exp_primes;
    while(k > 1){
        int p = lp[k];
        int cnt = 0;
        while(k % p == 0){
            k /= p;
            cnt++;
        }
        exp_primes[p] = cnt;
    }

    for(int i = 0; i < n; ++i){
        int c; cin >> c;
        while(c > 1){
            int p = lp[c];
            int cnt = 0;
            while(c % p == 0){
                c /= p;
                cnt++;
            }
            if(cnt >= exp_primes[p]){
                exp_primes.erase(p);
            }
        }
    }
    cout << (exp_primes.empty() ? "Yes\n" : "No\n");
}