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
        int n, x;
        cin >> x >> n;
        int ans = 0;
        for(int i = 1; i * i <= x; ++i){
            if(x % i) continue;
            if(x / i >= n) ans = max(ans, i);
            if(i >= n) ans = max(ans, x / i);
        }
        cout << ans << '\n';
    }
}
