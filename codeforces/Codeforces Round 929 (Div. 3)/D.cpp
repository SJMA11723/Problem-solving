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
        sort(arr, arr + n);
        if(arr[0] != arr[1]){
            cout << "YES\n";
            continue;
        }

        bool ok = false;
        for(int i = 0; i < n; ++i)
            if(arr[i] % arr[0]) ok = true;
        cout << (ok ? "YES\n" : "NO\n");
    }
}
