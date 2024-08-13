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
        int arr2[n], ans = -1;
        for(int k = 1; k <= 1024; ++k){
            for(int i = 0; i < n; ++i) arr2[i] = k ^ arr[i];
            sort(arr2, arr2 + n);
            if(equal(arr, arr + n, arr2, arr2 + n)){
                ans = k;
                break;
            }
        }
        cout << ans << '\n';
    }
}
