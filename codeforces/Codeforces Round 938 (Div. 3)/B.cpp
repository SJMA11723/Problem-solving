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
        int n, c, d; cin >> n >> c >> d;
        int arr[n * n];
        for(int i = 0; i < n * n; ++i) cin >> arr[i];

        int arr2[n * n], num = *min_element(arr, arr + n * n);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                arr2[i * n + j] = num;
                num += d;
            }
            num += c - n * d;
        }

        sort(arr, arr + n * n);
        sort(arr2, arr2 + n * n);

        bool ok = true;
        for(int i = 0; i < n * n; ++i) ok = ok && (arr[i] == arr2[i]);
        cout << (ok ? "YES\n" : "NO\n");
    }
}
