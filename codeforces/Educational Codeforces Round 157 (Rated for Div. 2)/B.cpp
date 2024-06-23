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
        int arr[2 * n];
        for(int i = 0; i < 2 * n; ++i) cin >> arr[i];
        sort(arr, arr + 2 * n);
        cout << arr[n - 1] + arr[2 * n - 1] - arr[n] - arr[0] << '\n';
        for(int i = 0; i < n; ++i) cout << arr[i] << ' ' << arr[i + n] << '\n';
    }
}
