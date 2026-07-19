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

#define MAXN 1000000

const int MOD = 1e7 + 7;

void criba(int n, vi &primos){
    vector<bool> no_primo(n + 1);
    no_primo[0] = no_primo[1] = 1;
    for(ll i = 3; i * i <= n; i += 2){
        if(no_primo[i]) continue;
        for(ll j = i * i; j <= n; j += 2 * i)
            no_primo[j] = 1;
    }
    primos.pb(2);
    for(int i = 3; i <= n; i += 2)
        if(!no_primo[i]) primos.pb(i);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vi primos;
    criba(MAXN, primos);

    int n; cin >> n;
    while(n){
        int tmp = n;
        int ans = 1;
        for(int p : primos){
            if(p > n) break;
            ll powp = 1;
            int e = 0;
            while(powp <= n){
                powp *= p;
                e += n / powp;
            }
            ans = 1ll * (e + 1) * (e + 2) / 2 % MOD * ans % MOD;
        }
        cout << ans << '\n';
        cin >> n;
    }
}
