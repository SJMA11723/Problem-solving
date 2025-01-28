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
    int t; cin >> t;
    while(t--){
        int n, I;
        long double p;
        cin >> n >> p >> I;
        long double ans = p;
        for(int i = 0; i + 1 < I; ++i) ans *= 1 - p;
        long double powcn = p ? 1 : 0;
        for(int i = 0; i < n; ++i) powcn *= 1 - p;
        ans /= 1 - powcn;
        cout << fixed << setprecision(4) << ans << '\n';
    }
}
