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
        int cub[30] = {};
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            for(int j = 0; j < 30; ++j) cub[j] += (bool)(x & (1 << j));
        }
        int g = 0;
        for(int i = 0; i < 30; ++i){
            if(!cub[i]) continue;
            g = gcd(g, cub[i]);
        }

        for(int d = 1; d <= n; ++d)
            if(g % d == 0) cout << d << ' ';
        cout << '\n';
    }
}
