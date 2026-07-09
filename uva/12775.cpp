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

int gcd_ext(int a, int b, ll &x, ll &y){
    if(!b){x = 1; y = 0; return a;}
    ll x1, y1;
    int g = gcd_ext(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}

bool encuentra_solucion(int a, int b, int c, ll &x, ll &y, ll &g){
    g = gcd_ext(abs(a), abs(b), x, y);
    if(c % g) return false;
    x *= c / g;
    y *= c / g;
    if(a < 0) x = -x;
    if(b < 0) y = -y;
    return true;
}

void cambia_solucion(ll &x, ll &y, int a, int b, ll cnt, ll g = 1){
    x += cnt * b / g;
    y -= cnt * a / g;
}

ll cuenta_soluciones(int a, int b, int c, int minx, int maxx, int miny, int maxy){
    ll x, y, g;
    if(!encuentra_solucion(a, b, c, x, y, g)) return 0;
    a /= g;
    b /= g;
    int sgn_a = a > 0 ? 1 : -1;
    int sgn_b = b > 0 ? 1 : -1;
    
    cambia_solucion(x, y, a, b, (minx - x) / b);
    if(x < minx) cambia_solucion(x, y, a, b, sgn_b);
    if(x > maxx) return 0;
    ll lx1 = x;
    cambia_solucion(x, y, a, b, (maxx - x) / b);
    if(x > maxx) cambia_solucion(x, y, a, b, -sgn_b);
    ll rx1 = x;

    cambia_solucion(x, y, a, b, -(miny - y) / a);
    if(y < miny) cambia_solucion(x, y, a, b, -sgn_a);
    if(y > maxy) return 0;
    ll lx2 = x;
    cambia_solucion(x, y, a, b, -(maxy - y) / a);
    if(y > maxy) cambia_solucion(x, y, a, b, sgn_a);
    ll rx2 = x;
    if(rx2 < lx2) swap(lx2, rx2);

    ll lx = max(lx1, lx2);
    ll rx = min(rx1, rx2);

    if(rx < lx) return 0;
    return (rx - lx) / abs(b) + 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    for(int tt = 1; tt <= t; ++tt){
        int a, b, c, p; cin >> a >> b >> c >> p;
        int g = __gcd(a, __gcd(b, c));
        if(p % g){
            cout << "Case " << tt << ": 0\n";
            continue;
        }
        a /= g;
        b /= g;
        c /= g;
        p /= g;
        ll ans = 0;
        for(int i = 0; i <= p; i += c) ans += cuenta_soluciones(a, b, p - i, 0, p, 0, p);
        cout << "Case " << tt << ": " << ans << '\n';
    }
}