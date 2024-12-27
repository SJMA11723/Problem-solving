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
        int n, a, b, c;
        cin >> n >> a >> b >> c;
        int ans = n / (a + b + c) * 3;
        n %= a + b + c;
        if(n){
            if(n <= a) ans++;
            else if(n <= a + b) ans += 2;
            else ans += 3;
        }
        cout << ans << '\n';
    }
}
