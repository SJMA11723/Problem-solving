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
        int n, k; cin >> n >> k;
        bool ans[n / k][n / k];
        for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j){
            char x; cin >> x;
            ans[i / k][j / k] = x - '0';
        }

        n /= k;
        for(int i = 0; i < n; ++i, cout << '\n')
            for(int j = 0; j < n; ++j) cout << ans[i][j];
    }
}
