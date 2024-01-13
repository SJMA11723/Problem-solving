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
        int a[n], b[n];
        int min_a = INT_MAX, min_b = INT_MAX;
        for(int i = 0; i < n; ++i){
            cin >> a[i];
            min_a = min(min_a, a[i]);
        }
        for(int i = 0; i < n; ++i){
            cin >> b[i];
            min_b = min(min_b, b[i]);
        }

        int64_t ans = 0;
        for(int i = 0; i < n; ++i){
            int64_t dif_a = a[i] - min_a;
            int64_t dif_b = b[i] - min_b;
            ans += max(dif_a, dif_b);
        }
        cout << ans << '\n';
    }
}
