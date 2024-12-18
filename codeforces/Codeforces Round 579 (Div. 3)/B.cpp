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
        int arr[4 * n];
        for(int &x : arr) cin >> x;
        sort(arr, arr + 4 * n);
        int area = arr[0] * arr[4 * n - 1];

        bool ans = true;
        for(int i = 0; i < n; ++i){
            if(arr[2 * i] == arr[2 * i + 1] && arr[4 * n - 1 - 2 * i] == arr[4 * n - 1 - 2 * i - 1] && arr[2 * i] * arr[4 * n - 1 - 2 * i] == area) continue;
            ans = false;
        }

        cout << (ans ? "YES\n" : "NO\n");
    }
}
