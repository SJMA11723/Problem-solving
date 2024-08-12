/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define EPS 1e-6

using namespace std;

long double dist(long double a, long double b, long double c, long double d){
    return sqrt((a - c) * (a - c) + (b - d) * (b - d));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int x[n], y[n];
        for(int i = 0; i < n; ++i) cin >> x[i] >> y[i];
        int xs, ys; cin >> xs >> ys;
        int xt, yt; cin >> xt >> yt;

        bool ok = true;
        for(int i = 0; i < n; ++i) ok = ok && (dist(xs, ys, xt, yt) < dist(x[i], y[i], xt, yt));

        cout << (ok ? "YES\n" : "NO\n");
    }
}

