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
        for(int &x : arr) cin >> x;

        bool ok = false;
        for(int i = 1; i < n; ++i){
            if(min(arr[i - 1], arr[i]) * 2 > max(arr[i - 1], arr[i])) ok = true;
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
}
