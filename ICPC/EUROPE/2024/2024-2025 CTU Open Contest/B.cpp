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
#define EPS 1e-12
#define DIFF 1e-5

const ll MOD = 1e9 + 7;

template<typename T> struct point{
    T x, y;

    template<typename T2> point operator-(point<T2> b){
        return {x - b.x, y - b.y};
    }

    template<typename T2> point operator+(point<T2> b){
        return {x + b.x, y + b.y};
    }

    point operator+(T d){
        return {x + d, y + d};
    }

    template<typename T2> point operator-(T2 d){
        return {x - d, y - d};
    }

    template<typename T2> point operator*(T2 d){
        return {x * d, y * d};
    }

    template<typename T2> point operator/(T2 d){
        return {x / d, y / d};
    }

    ld norm(){
        return sqrt(x * x + y * y);
    }
};

struct circle{
    point<int> O;
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
    point<ld> d = {(C2.O - C1.O).x, (C2.O - C1.O).y};
    ld d2 = sq(d);
    if (d2 == 0) {assert(r1 != r2); return 0;} // concentric circles
    ld pd = (d2 + r1*r1 - r2*r2)/2; // = |O_1P| * d
    ld h2 = r1*r1 - pd*pd/d2; // = hˆ2
    if (h2 >= 0) {
    point<ld> o1{C1.O.x, C1.O.y};
    point<ld> p = o1 + d*pd/d2, h = perp(d) * sqrt(h2/d2);
    out = {p-h, p+h};
    }
    return 1 + sgn(h2);
}
/// termina geo blackbox

bool check(vector<circle> &circles, const long double MAXD){
    int n = sz(circles);
    if(n == 1){
        return true;
    }

    vector<point<ld>> inter;
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            pair<point<ld>, point<ld>> P;
            if(!circle_circle({circles[i].O, circles[i].r + MAXD}, {circles[j].O, circles[j].r + MAXD}, P)){
                //cerr << "Circ " << i << " no interseca con circ " << j << endl;
                return false;
            }
            inter.pb(P.fi);
            inter.pb(P.se);
        }
    }

    if(inter.empty()){
        //cerr << "Interseccion vacia" << endl;
        return false;
    }

    for(point<ld> &p : inter){
        bool ok = true;
        for(int i = 0; i < n; ++i){
            point<ld> diff = {circles[i].O.x - p.x, circles[i].O.y - p.y};
            if( !(diff.norm() < circles[i].r + MAXD + EPS) ){
                //cerr << "punto de interseccion (" << p.x << ", " << p.y << ") no esta contenido en circ " << i << endl;
                //cerr << diff.norm() << ' ' << circles[i].r + MAXD << endl;
                ok = false;
                break;
            }
        }
        if(ok){
            //cerr << "punto de interseccion (" << p.x << ", " << p.y << ") SI esta contenido todos los circ " << endl;
            return true;
        }
    }

    //cerr << "Ningun punto de interseccion esta contenido en todos los circs" << endl;
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    point<int> arr[n];
    int R[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i].x >> arr[i].y >> R[i];
    }

    vector<circle> minimal_circles;
    for(int i = 0; i < n; ++i){
        //ld r1 = MAXD + R[i];
        bool ok = true;
        for(int j = 0; j < n; ++j){
            if(i == j) continue;
            //ld r2 = MAXD + R[j];
            point<int> diff = arr[j] - arr[i];
            if(sq(diff) <= (R[i] - R[j]) * (R[i] - R[j]) && R[j] <= R[i]){
                ok = false;
                break;
            }
        }
        if(ok) minimal_circles.pb({arr[i], R[i]});
    }

    ld l = 0, r = 2829;
    for(int K = 0; K < 100 && fabs(r - l) > DIFF; ++K){
        ld mid = (l + r) / 2;
        //cout << "BIN: " << l << ' ' << r << ' ' << mid << '\n';
        if(check(minimal_circles, mid)) r  = mid;
        else l = mid;
    }
    cout << fixed << setprecision(6) << l << '\n';
}