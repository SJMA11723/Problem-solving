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
        int arr[n], ord[n];
        int mini = INT_MAX;
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
            ord[i] = arr[i];
            mini = min(mini, arr[i]);
        }
        sort(ord, ord + n);
        bool ok = true;
        for(int i = 0; i < n; ++i){
            if(arr[i] == ord[i]) continue;
            if(arr[i] % mini){
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}
