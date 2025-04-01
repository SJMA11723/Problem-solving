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
        int n, x; cin >> n >> x;
        int arr[n];
        for(int &v : arr) cin >> v;
        sort(arr, arr + n, greater<int>());

        int len = 1, ans = 0;
        for(int i = 0; i < n; ++i){
            if(1ll * len * arr[i] >= x){
                ans++;
                len = 1;
            } else len++;
        }
        cout << ans << '\n';
    }
}
