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
        int ans = 0;
        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                if(arr[i] >= arr[j]) ans++;
            }
        }
        cout << ans << '\n';
    }
}
