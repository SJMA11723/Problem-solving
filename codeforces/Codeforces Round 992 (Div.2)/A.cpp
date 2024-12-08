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
        int n, k; cin >> n >> k;
        int arr[n];
        for(int &x : arr) cin >> x;
        int ans = -1;
        for(int i = 0; i < n && ans == -1; ++i){
            bool ok = true;
            for(int j = 0; j < n; ++j){
                if(i == j) continue;
                if(abs(arr[i] - arr[j]) % k == 0) ok = false;
            }
            if(ok) ans = i + 1;
        }
        if(ans == -1) cout << "NO\n";
        else cout << "YES\n" << ans << '\n';
    }
}
