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
        int n, q; cin >> n >> q;
        int64_t arr[2 * n + 1]; arr[0] = 0;
        for(int i = 1; i <= n; ++i){
            cin >> arr[i];
            arr[i + n] = arr[i];
            arr[i] += arr[i - 1];
        }
        for(int i = n + 1; i <= 2 * n; ++i) arr[i] += arr[i - 1];

        while(q--){
            int64_t l, r; cin >> l >> r;
            int shift_r = (r - 1) / n + 1;
            int64_t ans = arr[n] * (shift_r - 1) + arr[(r - 1) % n + shift_r] - arr[shift_r - 1];

            l--;
            if(l){
                int shift_l = (l - 1) / n + 1;
                ans -= arr[n] * (shift_l - 1) + arr[(l - 1) % n + shift_l] - arr[shift_l - 1];
            }

            cout << ans << '\n';
        }
    }
}
