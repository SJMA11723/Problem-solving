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
        int64_t arr[n];
        for(int64_t &x : arr) cin >> x;
        if(n % 2){
            int64_t ans = LLONG_MAX;
            int64_t L[n] = {}, R[n] = {};
            L[1] = arr[1] - arr[0];
            for(int i = 3; i < n; i += 2) L[i] = max(L[i - 2], arr[i] - arr[i - 1]);

            R[n - 2] = arr[n - 1] - arr[n - 2];
            for(int i = n - 4; 0 <= i; i -= 2) R[i] = max(R[i + 2], arr[i + 1] - arr[i]);

            for(int i = 0; i < n; i += 2) /// itero por la celda que dejo sola
                ans = min(ans, max({1ll, (i ? L[i - 1] : 0), (i + 1 < n ? R[i + 1] : 0)}));
            cout << ans << '\n';
        } else {
            int64_t ans = 1;
            for(int i = 1; i < n; i += 2) ans = max(ans, arr[i] - arr[i - 1]);
            cout << ans << '\n';
        }
    }
}
