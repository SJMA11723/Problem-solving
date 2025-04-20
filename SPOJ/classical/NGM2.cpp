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
    int n, k; cin >> n >> k;
    int arr[k];
    for(int &x : arr) cin >> x;

    int64_t ans = n;
    int lim = 1 << k;
    for(int mask = 1; mask < lim; ++mask){
        int64_t mlcm = 1;
        for(int i = 0; i < k && mlcm <= n; ++i){
            if(is_on(mask, i)) mlcm = mlcm / __gcd(mlcm, (int64_t)arr[i]) * arr[i];
        }

        ans += n / mlcm * (__builtin_parity(mask) ? -1 : 1);
    }

    cout << ans << '\n';
}
