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
        int64_t odd = 0;
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
            if(arr[i] % 2) odd = max(odd, arr[i]);
        }
        if(!odd){
            cout << "0\n";
            continue;
        }

        sort(arr, arr + n);
        int64_t ans = 0;
        bool greater = false;
        for(int64_t x : arr){
            if(x % 2) continue;

            if(odd < x) greater = true;

            //cout << x << ' ' << odd << '\n';
            ans++;
            x += odd;

            odd = x;
            //cout << "New odd " << odd << '\n';
        }
        if(greater) ans++;
        cout << ans << '\n';
    }
}
