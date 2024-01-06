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
        int64_t n, k; cin >> n >> k;
        int64_t arr[n];
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            int power = 1;
            while(x--) power *= 10;
            arr[i] = power;
        }
        sort(arr, arr + n);

        k++;
        int64_t ans = 0;
        for(int i = 0; i < n; ++i){
            int64_t mini = min(k, i + 1 < n ? arr[i + 1] / arr[i] - 1 : LLONG_MAX);
            k -= mini;
            ans += mini * arr[i];
        }
        cout << ans << '\n';
    }
}
