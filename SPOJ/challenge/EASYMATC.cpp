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
    int t; cin >> t;
    while(t--){
        int64_t n, m, a, d;
        cin >> n >> m >> a >> d;
        int64_t arr[5] = {a, a + d, a + 2 * d, a + 3 * d, a + 4 * d};

        n--;
        int64_t ans = m - n;
        int lim = 1 << 5;
        for(int mask = 1; mask < lim; ++mask){
            int64_t mlcm = 1;
            for(int i = 0; i < 5 && mlcm <= m; ++i){
                if(is_on(mask, i)) mlcm = mlcm / __gcd(mlcm, arr[i]) * arr[i];
            }

            ans += n / mlcm * (__builtin_parity(mask) ? 1 : -1);
            ans -= m / mlcm * (__builtin_parity(mask) ? 1 : -1);
        }
        cout << ans << '\n';
    }
}
