/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define EPS 1e-6

using namespace std;

bool check(int n, int x[], int v[], const long double t){
    long double mini = LLONG_MAX, maxi = LLONG_MIN;
    for(int i = 0; i < n; ++i){
        maxi = max(maxi, x[i] - t * v[i]);
        mini = min(mini, x[i] + t * v[i]);
    }
    return maxi <= mini;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int x[n], v[n];
    for(int i = 0; i < n; ++i) cin >> x[i] >> v[i];

    long double l = -1e9, r = 1e9;
    for(int i = 0; i < 55; ++i){
        long double mid = l + (r - l) / 2;
        if(check(n, x, v, mid)) r = mid;
        else l = mid;
    }
    cout << fixed << setprecision(7) << l << '\n';
}
