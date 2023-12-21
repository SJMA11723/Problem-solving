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
        int ans = 1;
        for(int i = 1; i * i <= n && i <= k; ++i){
            if(n % i == 0){
                ans = max(ans, i);
                if(n / i <= k) ans = max(ans, n / i);
            }
        }
        cout << n / ans << '\n';
    }
}
