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
        int lc = 0;
        while(lc < n && arr[n - 1 - lc] == arr[n - 1]) lc++;
        if(lc == n){
            cout << "-1\n";
            continue;
        }
        cout << n - lc << ' ' << lc << '\n';
        for(int i = 0; i < n - lc; ++i) cout << arr[i] << ' ';
        cout << '\n';
        for(int i = n - lc; i < n; ++i) cout << arr[i] << ' ';
        cout << '\n';
    }
}
