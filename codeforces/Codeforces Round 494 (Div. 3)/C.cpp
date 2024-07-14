/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k; cin >> n >> k;
    long double a[n];
    for(long double &x : a) cin >> x;

    long double ans = 0;
    for(int i = 0; i < n; ++i){
        long double sum = 0;
        for(int j = 0; i + j < n; ++j){
            sum += a[i + j];
            if(j >= k - 1) ans = max(ans, sum / (j + 1));
        }
    }
    cout << fixed << setprecision(7) << ans << '\n';
}
