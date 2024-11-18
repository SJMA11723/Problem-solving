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
        int n, k; cin >> n >> k;
        if(k == 1){
            cout << n << '\n';
            continue;
        }
        int ans = 0;
        while(n){
            ans += n % k;
            n /= k;
        }
        cout << ans << '\n';
    }
}
