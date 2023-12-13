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
        int n, x; cin >> n >> x;
        int arr[n];
        int ans = -1, sum = 0;
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
            sum += arr[i];
            sum %= x;
            if(sum) ans = i + 1;
        }

        sum = 0;
        for(int i = n - 1; 0 <= i; --i){
            sum += arr[i];
            sum %= x;
            if(sum) ans = max(ans, n - i);
        }
        cout << ans << '\n';
    }
}
