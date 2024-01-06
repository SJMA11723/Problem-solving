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
        for(int i = 0; i < n; ++i) cin >> arr[i];

        int ans[n], idx = 0, pref = 0;
        for(int b = 30; 0 <= b; --b){
            if(pref & (1 << b)) continue;

            int idx_num = -1, rem = 0;
            for(int i = 0; i < n; ++i){
                if(arr[i] != -1 && (arr[i] & (1 << b)) && arr[i] - (arr[i] & pref) > rem){
                    idx_num = i;
                    rem = arr[i] - (arr[i] & pref);
                }
            }

            if(idx_num != -1){
                ans[idx] = arr[idx_num];
                pref |= ans[idx++];
                arr[idx_num] = -1;
            }
        }

        for(int i = 0; i < n; ++i)
            if(arr[i] != -1) ans[idx++] = arr[i];

        for(int i = 0; i < n; ++i) cout << ans[i] << ' ';
        cout << '\n';
    }
}
