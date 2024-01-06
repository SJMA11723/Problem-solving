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
        sort(arr, arr + n);
        bool ok = true;
        for(int i = 1; i < n && ok; ++i)
            if(arr[i] == arr[i - 1]) ok = false;
        cout << (ok ? "YES\n" : "NO\n");
    }
}
