/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll gcdExtendido(ll a, ll b, ll &x, ll &y){
    if(!b){
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll g = gcdExtendido(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}

bool encuentra_solucion(ll a, ll b, ll c, ll &x, ll &y, ll &g){
    g = gcdExtendido(abs(a), abs(b), x, y);
    if(c % g) return false;
    x *= c / g;
    y *= c / g;
    if(a < 0) x = -x;
    if(b < 0) y = -y;
    return true;
}

void cambia_solucion(ll &x, ll &y, ll a, ll b, ll cnt) {
    x += cnt * b;
    y -= cnt * a;
}

ll cuenta_soluciones(ll a, ll b, ll c, ll minx, ll maxx, ll miny, ll maxy) {
    ll x, y, g;
    if (!encuentra_solucion(a, b, c, x, y, g)) return 0;

    a /= g;
    b /= g;

    int sign_a = a > 0 ? +1 : -1;
    int sign_b = b > 0 ? +1 : -1;

    cambia_solucion(x, y, a, b, (minx - x) / b);
    if (x < minx) cambia_solucion(x, y, a, b, sign_b);
    if (x > maxx) return 0;
    ll lx1 = x;

    cambia_solucion(x, y, a, b, (maxx - x) / b);
    if (x > maxx) cambia_solucion(x, y, a, b, -sign_b);
    ll rx1 = x;

    cambia_solucion(x, y, a, b, -(miny - y) / a);
    if (y < miny) cambia_solucion(x, y, a, b, -sign_a);
    if (y > maxy) return 0;
    ll lx2 = x;

    cambia_solucion(x, y, a, b, -(maxy - y) / a);
    if (y > maxy) cambia_solucion(x, y, a, b, sign_a);
    ll rx2 = x;

    if (lx2 > rx2) swap(lx2, rx2);

    ll lx = max(lx1, lx2);
    ll rx = min(rx1, rx2);

    if (lx > rx) return 0;
    return (rx - lx) / abs(b) + 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    for(int tt = 1; tt <= t; ++tt){
        ll a, b, c, x1, x2, y1, y2;
        cin >> a >> b >> c >> x1 >> x2 >> y1 >> y2;
        c *= -1;
        cout << "Case " << tt << ": ";
        if(!a && !b){
            if(c) cout << "0\n";
            else cout << (x2 - x1 + 1) * (y2 - y1 + 1) << '\n';
        } else if(!a){
            if(c % b || c/b < y1 || y2 < c/b) cout << "0\n";
            else cout << x2 - x1 + 1 << '\n';
        } else if(!b){
            if(c % a || c/a < x1 || x2 < c/a) cout << "0\n";
            else cout << y2 - y1 + 1 << '\n';
        } else cout << cuenta_soluciones(a, b, c, x1, x2, y1, y2) << '\n';
    }
}
