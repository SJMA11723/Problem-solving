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
        int n; cin >> n;
        int x[n], y[n];
        for(int i = 0; i < n; ++i) cin >> x[i] >> y[i];
        sort(x, x + n);
        sort(y, y + n);
        if(0 <= x[0] || 0 <= y[0] || y[n - 1] <= 0 || x[n - 1] <= 0) cout << "YES\n";
        else cout << "NO\n";
    }
}
