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
    int k; cin >> k;
    int x[k], y[k];
    for(int i = 0; i < k; ++i)
        cin >> x[i] >> y[i];

    long double ans = 1e18;
    for(int i = 0; i < k; ++i){
        long double prom = 0;
        for(int j = 0; j < k; ++j)
            prom += sqrt( (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
        prom /= k - 1;
        ans = min(ans, prom);
    }
    cout << fixed << setprecision(8) << ans << '\n';
}
