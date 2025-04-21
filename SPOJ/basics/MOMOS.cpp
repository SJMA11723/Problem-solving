/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define is_on(n, i) ((n) & (1ll << (i)))

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int64_t n, k; cin >> n >> k;
    int64_t arr[k];
    for(int64_t &x : arr) cin >> x;

    if(k <= 20){
        int64_t ans = n - 1;
        int lim = 1 << k;
        for(int mask = 1; mask < lim; ++mask){
            __int128_t mlcm = 1;
            for(int i = 0; i < k && mlcm < n; ++i)
            if(is_on(mask, i)){
                mlcm = mlcm / __gcd(mlcm, (__int128_t)arr[i]) * arr[i];
            }
            ans += (n - 1) / mlcm * (__builtin_parity(mask) ? -1 : 1);
        }
        cout << ans << '\n';
    } else {
        bool vis[n + 1] = {};
        bool vis2[n + 1] = {};
        int ans = n;
        for(int i = 0; i < k; ++i){
            if(vis[ arr[i] ]) continue;
            vis[ arr[i] ] = true;

            for(int j = 0; j < n; j += arr[i]){
                if(!vis2[j]) ans--;
                vis2[j] = true;
            }
        }
        cout << ans << '\n';
    }
}
