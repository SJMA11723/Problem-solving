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
        int n, c; cin >> n >> c;
        int arr[n];
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
            arr[i] += i + 1;
        }
        sort(arr, arr + n);
        int ans = 0;
        for(int i = 0; i < n; ++i){
            if(arr[i] <= c){
                ans++;
                c -= arr[i];
            } else break;
        }
        cout << ans << '\n';
    }
}
