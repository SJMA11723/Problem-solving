/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

__int128_t gcd_extendido(__int128_t a, __int128_t b, __int128_t &x, __int128_t &y){
    if(!b){
        x = 1;
        y = 0;
        return a;
    }
    __int128_t x1, y1;
    __int128_t g = gcd_extendido(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}

bool encuentra_solucion(__int128_t a, __int128_t b, __int128_t c, __int128_t &x, __int128_t &y, __int128_t &g){
    g = gcd_extendido(abs(a), abs(b), x, y);
    if(c % g) return false;
    x *= c / g;
    y *= c / g;
    if(a < 0) x = -x;
    if(b < 0) y = -y;
    return true;
}

void cambia_solucion(__int128_t &x, __int128_t &y, __int128_t a, __int128_t b, __int128_t cnt, __int128_t g = 1) {
    x += cnt * b / g;
    y -= cnt * a / g;
}

int64_t min_sol(__int128_t a, __int128_t b, __int128_t c, __int128_t minx, __int128_t maxx, __int128_t miny, __int128_t maxy) {
    __int128_t x, y, g;
    if(!encuentra_solucion(a, b, c, x, y, g)) return LLONG_MIN;

    a /= g;
    b /= g;

    __int128_t sign_a = a > 0 ? +1 : -1;
    __int128_t sign_b = b > 0 ? +1 : -1;

    cambia_solucion(x, y, a, b, (minx - x) / b);
    if(x < minx) cambia_solucion(x, y, a, b, sign_b);
    if(x > maxx) return LLONG_MIN;
    __int128_t lx1 = x;

    cambia_solucion(x, y, a, b, (maxx - x) / b);
    if(x > maxx) cambia_solucion(x, y, a, b, -sign_b);
    __int128_t rx1 = x;

    cambia_solucion(x, y, a, b, -(miny - y) / a);
    if(y < miny) cambia_solucion(x, y, a, b, -sign_a);
    if(y > maxy) return LLONG_MIN;
    __int128_t lx2 = x;

    cambia_solucion(x, y, a, b, -(maxy - y) / a);
    if(y > maxy) cambia_solucion(x, y, a, b, sign_a);
    __int128_t rx2 = x;

    if(lx2 > rx2) swap(lx2, rx2);

    __int128_t lx = max(lx1, lx2);
    __int128_t rx = min(rx1, rx2);

    if(lx > rx) return LLONG_MIN;

    return lx;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int64_t X, Y; cin >> X >> Y;

    if(!X){
        if(2 % abs(Y) == 0) cout << 2 / Y << " 0\n";
        else cout << "-1\n";
        return 0;
    }

    if(!Y){
        if(2 % abs(X) == 0) cout << "0 " << 2 / X << '\n';
        else cout << "-1\n";
        return 0;
    }

    int64_t A = min_sol(-Y, X, 2, -1e18, 1e18, -1e18, 1e18);

    if(A != LLONG_MIN) cout << A << ' ' << (int64_t)(((__int128_t)Y * A + 2) / X) << '\n';
    else {
        A = min_sol(Y, -X, 2, -1e18, 1e18, -1e18, 1e18);
        if(A != LLONG_MIN) cout << A << ' ' << (int64_t)(((__int128_t)A * Y - 2) / X) << '\n';
        else cout << "-1\n";
    }
}
