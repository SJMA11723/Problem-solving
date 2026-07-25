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

ll phi(ll n){
    ll res = n;
    for(ll d = 2; d * d <= n; ++d){
        if(n % d) continue;
        res -= res / d;
        while(n % d == 0) n /= d;
    }
    if(n > 1) res -= res / n;
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, k; cin >> n >> k;
    ll cnt = (k + 1) / 2;
    while(cnt-- > 0 && n > 1) n = phi(n);
    cout << n % MOD << '\n';
}