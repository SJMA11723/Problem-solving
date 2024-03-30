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
        int64_t n, x, y; cin >> n >> x >> y;
        int arr[x];
        for(int i = 0; i < x; ++i){
            cin >> arr[i];
            arr[i]--;
        }
        sort(arr, arr + x);
        int64_t ans = x - 2;
        for(int i = 0; i + 1 < x; ++i){
            if((arr[i] + 2) % n == arr[i + 1]) ans++;
        }
        if((arr[x - 1] + 2) % n == arr[0]) ans++;

        cout << ans << '\n';
    }
}
