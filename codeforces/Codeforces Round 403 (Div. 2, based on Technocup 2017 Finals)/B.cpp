/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

bool check(int n, int x[], int v[], long double t){
    long double maxi = LLONG_MIN, mini = LLONG_MAX;
    for(int i = 0; i < n; ++i){
        maxi = max(maxi, x[i] - v[i] * t);
        mini = min(mini, x[i] + v[i] * t);
    }
    return maxi <= mini;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int x[n], v[n];
    for(int &u : x) cin >> u;
    for(int &u : v) cin >> u;

    long double l = 0, r = INT_MAX;
    for(int i = 0; i < 100; ++i){
        long double mid = l + (r - l) / 2;
        if(check(n, x, v, mid)) r = mid;
        else l = mid;
    }
    cout << fixed << setprecision(6) << l << '\n';
}
