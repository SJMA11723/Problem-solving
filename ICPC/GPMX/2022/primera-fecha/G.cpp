#/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
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
#define EPS 1e-4

const ll MOD = 1e9 + 7;

template<typename T> struct point{
    T x, y;

    point operator-(point b){
        return {x - b.x, y - b.y};
    }

    point operator+(point b){
        return {x + b.x, y + b.y};
    }

    point operator*(T d){
        return {x * d, y * d};
    }

    point operator/(T d){
        return {x / d, y / d};
    }

    ld norm(){
        return sqrt(x * x + y * y);
    }
};

struct circle{
    point<ll> O;
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

int circle_circle(circle C1, circle C2, pair<point<ld>, point<ld>> &out) {
    point<ld> o1 = {C1.O.x, C1.O.y}, o2 = {C2.O.x, C2.O.y};
    ld r1 = C1.r, r2 = C2.r;
    point<ld> d = {(C2.O - C1.O).x, (C2.O - C1.O).y};
    ld d2 = sq(d);
    if (d2 == 0) {assert(r1 != r2); return 0;}
    ld pd = (d2 + r1*r1 - r2*r2)/2;
    ld h2 = r1*r1 - pd*pd/d2;
    if (h2 >= 0) {
    point<ld> p = o1 + d*pd/d2, h = perp(d)*sqrt(h2/d2);
    out = {p-h, p+h};
    }
    return 1 + sgn(h2);
}

/// termina geo blackbox

bool check(int n, point<ll> arr[], int C[], const long double MAXD){
    bool erased[n] = {};
    for(int i = 0; i < n; ++i){
        if(erased[i]) continue;
        for(int j = 0; j < n; ++j){
            if(i == j || erased[j]) continue;
            point<ll> diff = arr[i] - arr[j];
            if(sq(diff) == 0 && C[i] == C[j]){
                erased[j] = true;
            } else if(C[i] * C[j] * diff.norm() + EPS < MAXD * (C[i] - C[j])){
                erased[j] = true;
            }
        }
    }
    vector<circle> minimal_circles;
    for(int i = 0; i < n; ++i){
        if(!erased[i]) minimal_circles.pb({arr[i], MAXD / C[i]});
    }

    n = sz(minimal_circles);
    if(n == 1){
        return true;
    }

    vector<point<ld>> inter;
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            pair<point<ld>, point<ld>> P;
            if(!circle_circle(minimal_circles[i], minimal_circles[j], P)){
                return false;
            }
            inter.pb(P.fi);
            inter.pb(P.se);
        }
    }

    if(inter.empty()){
        return false;
    }

    for(point<ld> &p : inter){
        bool ok = true;
        for(int i = 0; i < n; ++i){
            point<ld> diff = {minimal_circles[i].O.x - p.x, minimal_circles[i].O.y - p.y};
            if(diff.norm() > minimal_circles[i].r + EPS){
                ok = false;
                break;
            }
        }
        if(ok) return true;
    }

    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    point<ll> arr[n];
    int c[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i].x >> arr[i].y >> c[i];
    }
    ld l = 0, r = 1e12;
    for(int K = 0; K < 54; ++K){
        ld mid = (l + r) / 2;
        if(check(n, arr, c, mid)) r  = mid;
        else l = mid;
    }
    cout << fixed << setprecision(8) << l << '\n';
}