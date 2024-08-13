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
        int cub[31] = {};
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            cub[31 - __builtin_clz(x)]++;
        }

        int64_t ans = 1ll * n * (n - 1) / 2;
        int cnt = 0;
        for(int i = 0; i < 31; ++i){
            ans -= 1ll * cnt * cub[i];
            cnt += cub[i];
        }
        cout << ans << '\n';
    }
}
