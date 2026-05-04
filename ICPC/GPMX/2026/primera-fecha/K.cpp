/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

/**
 * Que Dios me ayude
 * 
 * Supongo que... otra vez +25 envios en un problema de geo
 * 
 * aaaaaaaaaaaaaaaaahahahahahahahahahah
 * 
 * me retiro de los problemas de geo con precision
 * 
 * teoria de numeros nunca me haria esto
 * 
 * teoria de grafos nunca me haria esto
*/

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
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

#define EPS 1e-8
#define ITER_TERN 60

const ll MOD = 1e9 + 7;

template<typename T> struct point{
    T x, y;
 
    point<T> operator-(point<T> b){
        return {x - b.x, y - b.y};
    }
 
    point<T> operator+(point<T> b){
        return {x + b.x, y + b.y};
    }
 
    point<T> operator+(T d){
        return {x + d, y + d};
    }
 
    point<T> operator-(T d){
        return {x - d, y - d};
    }
 
    point<T> operator*(T d){
        return {x * d, y * d};
    }
 
    point<T> operator/(T d){
        return {x / d, y / d};
    }
 
    ld norm(){
        return sqrtl(x * x + y * y);
    }
};

struct circle{
    point<ld> O;
    ld r;
};
 
/// inicia geo blackbox
template<typename T> T sq(point<T> p){
    return p.x * p.x + p.y * p.y;
}
 
template<typename T> point<T> perp(point<T> p){
    return {-p.y, p.x};
}
 
template<typename T> int sgn(T x){
    return (T(0) < x) - (x < T(0));
}
 
// circunferencia en el origen
int circle_circle(circle C1, circle C2, pair<point<ld>, point<ld>> &out) {
    ld r1 = C1.r, r2 = C2.r;
    point<ld> d = C2.O - C1.O;
    ld d2 = sq(d);
    if (d2 == 0) return 0;
    
    ld d_len = sqrtl(d2);
    ld pd = (d2 + r1*r1 - r2*r2) / (2.0 * d_len); 
    ld h2 = r1*r1 - pd*pd;
    h2 = max((ld)0.0, h2); 
    
    point<ld> p = C1.O + d * (pd / d_len);
    point<ld> h = perp(d) / d_len * sqrtl(h2);
    out = {p - h, p + h};
    return 1 + (h2 > 0);
}
/// termina geo blackbox

bool check(point<ld> &P, ld r, circle circles[], int n, ll R[]){
    circle circP{P.x, P.y, r};

    for(int i = 0; i < n; ++i){
        pair<point<ld>, point<ld>> out;
        if(!circle_circle(circles[i], circP, out))
            return false;
        
        point<ld> inter[2] = {out.fi, out.se};
        for(int a = 0; a < 2; ++a){
            bool ok = true;

            for(int k = 0; k < n; ++k){
                if(R[k] + EPS < (inter[a] - circles[k].O).norm()){
                    ok = false;
                    break;
                }
            }
            if(ok) return true;
        }
    }

    return false;
}

ld dist(point<ld> p, int n, circle arr[]){
    ld res = 0;
    for(int i = 0; i < n; ++i) res = max(res, (arr[i].O - p).norm() - arr[i].r);
    return res;
}

ld miny(ld x, int n, circle arr[]){
    ld l = -2e6, r = 2e6;
    for(int k = 0; k < ITER_TERN; ++k){
        ld t1 = l + (r - l) / 3;
        ld t2 = r - (r - l) / 3;
        ld v1 = dist({x, t1}, n, arr);
        ld v2 = dist({x, t2}, n, arr);
 
        if(v1 < v2) r = t2;
        else l = t1;
    }

    return l;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    ll px, py; cin >> px >> py;
    point<ld> P{(ld)px, (ld)py};

    circle arr[n];
    point<ll> O[n];
    ll R[n];
    for(int i = 0; i < n; ++i){
        cin >> O[i].x >> O[i].y >> R[i];
        arr[i].O.x = O[i].x;
        arr[i].O.y = O[i].y;
        arr[i].r = R[i];
    }

    bool in_inter = true;
    for(int i = 0; i < n; ++i){
        if(R[i] * R[i] < sq(O[i] - point<ll>{px, py})){
            in_inter = false;
            break;
        }
    }

    if(in_inter){
        cout << fixed << setprecision(16) << 0.0 << '\n';
        return 0;
    }

    ld l = -2e6, r = 2e6;
    for(int k = 0; k < ITER_TERN; ++k){
        ld t1 = l + (r - l) / 3;
        ld t2 = r - (r - l) / 3;
        ld v1 = dist({t1, miny(t1, n, arr)}, n, arr);
        ld v2 = dist({t2, miny(t2, n, arr)}, n, arr);
 
        if(v1 < v2) r = t2;
        else l = t1;
    }
    point<ld> p_inter{l, miny(l, n, arr)};
    l = 0;
    r = (p_inter - P).norm() + EPS;

    for(int k = 0; k < 50; ++k){
        ld mid = (l + r) / 2;
        if(check(P, mid, arr, n, R)) r = mid;
        else l = mid;
    }

    cout << fixed << setprecision(16) << r << '\n';
}
