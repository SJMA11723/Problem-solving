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
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
            if(arr[i] == i + 1) continue;
            if(i && arr[i] - arr[i - 1] == -1) swap(arr[i], arr[i - 1]);
        }

        for(int i = 1; i < n; ++i){
            if(arr[i] == i + 1) continue;
            if(arr[i] - arr[i - 1] == -1) swap(arr[i], arr[i - 1]);
        }

        cout << (is_sorted(arr, arr + n) ? "YES\n" : "NO\n");
    }
}
