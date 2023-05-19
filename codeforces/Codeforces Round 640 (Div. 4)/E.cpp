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
        int arr[n + 1]; arr[0] = 0;
        for(int i = 1; i <= n; ++i){
            cin >> arr[i];
            arr[i] += arr[i - 1];
        }
        bitset<64000001> cub;
        for(int i = 1; i <= n; ++i){
            for(int j = i + 1; j <= n; ++j) cub[ arr[j] - arr[i - 1] ] = 1;
        }

        int ans = 0;
        for(int i = 1; i <= n; ++i) if(cub[arr[i] - arr[i - 1]]) ans++;
        cout << ans << '\n';
    }
}
