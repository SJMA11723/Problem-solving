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

ll gcd_ext(ll a, ll b, ll &x, ll &y){
    if(!b) return x = 1, y = 0, a;
    ll d = gcd_ext(b, a % b, y, x);
    return y -= a / b * x, d;
}

ll crt(ll a, ll m, ll b, ll n){
    if(n > m) swap(a, b), swap(m, n);
    ll x, y, g = gcd_ext(m, n, x, y);
    if((a - b) % g) return -1;
    x = (b - a) % n * x % n / g * m + a;
    return x < 0 ? x + m / g * n : x;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    for(int tt = 1; tt <= t; ++tt){
        int n; cin >> n;
        ll x = 0, m = 1;
        bool ok = 1;
        while(n--){
            ll r, p; cin >> p >> r;
            x = crt(x, m, r, p);
            if(x == -1) ok = 0;
            m *= p;
        }
        cout << "Case " << tt << ": ";
        if(ok) cout << x << '\n';
        else cout << "Impossible\n";
    }
}