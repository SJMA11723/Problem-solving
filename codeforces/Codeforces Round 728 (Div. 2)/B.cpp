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
        int cub[2 * n + 1] = {};
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
            cub[ arr[i] ] = i + 1;
        }

        long long ans = 0;
        for(int i = 0; i < n; ++i){
            for(int m = arr[i]; m <= 2 * n; m += arr[i]){
                if(i + 1 < cub[m / arr[i]] && m == i + 1 + cub[m / arr[i]]) ans++;
            }
        }
        cout << ans << '\n';
    }
}
