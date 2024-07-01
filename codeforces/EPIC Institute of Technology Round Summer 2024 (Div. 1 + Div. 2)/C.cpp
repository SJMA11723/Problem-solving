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
        int arr[n];
        for(int &x : arr) cin >> x;

        /// t_s: tiempo de espera el siguiente
        /// s: valor del siguiente
        int64_t t_s = 0, s = 0, ans = 0;
        for(int i = n - 1; 0 <= i; --i){
            if(arr[i] > s){
                int bi = max(s, arr[i] - t_s); /// valor actual contando tiempo de espera del siguiente
                if(bi > s){ /// es mayor que el siguiente, entonces tarda arr[i] en llegar a 0
                    ans = max(ans, 1ll*arr[i]);
                    t_s = 0;
                } else { /// se cuenta cuanto tarda el sigueinte en llegar a (arr[i] - 1) para que arr[i] decrezca
                    int64_t t = t_s + s - arr[i] + 1;
                    ans = max(ans, t + arr[i]);
                    t_s = t;
                }
            } else {
                int64_t t = t_s + s - arr[i] + 1;
                ans = max(ans, t + arr[i]);
                t_s = t;
            }
            s = arr[i];
        }

        cout << ans << '\n';
    }
}
