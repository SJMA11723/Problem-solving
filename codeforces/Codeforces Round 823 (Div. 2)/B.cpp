/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

bool check(int n, int x[], int t[], long double T){
    long double maxi = LLONG_MIN, mini = LLONG_MAX;
    for(int i = 0; i < n; ++i){
        maxi = max(maxi, -T + t[i] + x[i]);
        mini = min(mini, T - t[i] + x[i]);
    }
    return maxi <= mini;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int x[n], T[n];
        for(int &v : x) cin >> v;
        for(int &v : T) cin >> v;

        long double l = 0, r = 4e8;
        for(int i = 0; i < 53; ++i){
            long double mid = l + (r - l) / 2;
            if(check(n, x, T, mid)) r = mid;
            else l = mid;
        }

        long double maxi = LLONG_MIN, mini = LLONG_MAX;
        for(int i = 0; i < n; ++i){
            maxi = max(maxi, -l + T[i] + x[i]);
            mini = min(mini, l - T[i] + x[i]);
        }
        cout << fixed << setprecision(7) << maxi << '\n';
    }
}
