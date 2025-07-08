#/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
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
#define EPS 1e-12
#define DIFF 1e-5
#define MAXITER 44 // minimum iterations in both x, y

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

ld dist(int n, point<int> arr[], int R[], const ld x, const ld y){
    ld res = 0;
    for(int i = 0; i < n; ++i){
        point<ld> p{arr[i].x - x, arr[i].y - y};
        res = max(res, p.norm() - R[i]);
    }
    return res;
}

ld opty(int n, point<int> arr[], int R[], const ld x){
    ld l = -1e3, r = 1e3;
    for(int K = 0; K < MAXITER; ++K){
        ld m1 = l + (r - l) / 3;
        ld m2 = r - (r - l) / 3;
        ld v1 = dist(n, arr, R, x, m1);
        ld v2 = dist(n, arr, R, x, m2);

        if(v1 < v2) r = m2;
        else l = m1;
    }

    return dist(n, arr, R, x, l);
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

    ld l = -1e3, r = 1e3;
    for(int K = 0; K < MAXITER; ++K){
        ld m1 = l + (r - l) / 3;
        ld m2 = r - (r - l) / 3;
        ld v1 = opty(n, arr, R, m1);
        ld v2 = opty(n, arr, R, m2);

        if(v1 < v2) r = m2;
        else l = m1;
    }

    cout << fixed << setprecision(6) << opty(n, arr, R, l) << '\n';
}
