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
        int cub[n + 1] = {};
        int types[n];
        for(int i = 0; i < n; ++i) cin >> types[i];
        for(int i = 0; i < n; ++i){
            int b; cin >> b;
            cub[ types[i] ] = max(cub[types[i]] , b);
        }

        int ans = 0;
        for(int i = 1; i <= n; ++i) ans += cub[i];
        cout << ans << '\n';
    }
}
