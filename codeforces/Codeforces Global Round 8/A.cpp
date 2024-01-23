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
        int a, b, n; cin >> a >> b >> n;
        if(a > b) swap(a, b);
        int ans = 0;
        while(a <= n && b <= n){
            if(ans % 2 == 0) a += b;
            else b += a;
            ans++;
        }
        cout << ans << '\n';
    }
}
