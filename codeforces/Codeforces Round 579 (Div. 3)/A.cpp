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
        int first;
        for(int i = 0; i < n; ++i){
            if(arr[i] == 1){
                first = i;
                break;
            }
        }
        rotate(arr, arr + first, arr + n);
        if(is_sorted(arr, arr + n)){
            cout << "YES\n";
            continue;
        }

        for(int i = 0; i < n; ++i){
            if(arr[i] == n){
                first = i;
                break;
            }
        }

        rotate(arr, arr + first, arr + n);
        reverse(arr, arr + n);
        if(is_sorted(arr, arr + n)){
            cout << "YES\n";
            continue;
        }

        cout << "NO\n";
    }
}
