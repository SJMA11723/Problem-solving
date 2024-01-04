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
        int a, b; cin >> a >> b;
        int ans = 0, dif = abs(a - b);
        for(int i = 10; 0 < i; --i){
            ans += dif / i;
            dif %= i;
        }
        cout << ans << '\n';
    }
}
