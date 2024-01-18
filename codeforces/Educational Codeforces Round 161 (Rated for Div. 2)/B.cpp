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
        int64_t cub[n + 2] = {};
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            cub[x]++;
        }

        int64_t ans = 0, sum = 0;
        for(int i = 0; i <= n; ++i){
            ans += cub[i] * (cub[i] - 1) / 2 * sum;
            ans += cub[i] * (cub[i] - 1) * (cub[i] - 2) / 6;
            sum += cub[i];
        }
        cout << ans << '\n';
    }
}
