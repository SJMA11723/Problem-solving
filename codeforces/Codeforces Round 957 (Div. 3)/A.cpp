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
        int a, b, c; cin >> a >> b >> c;
        int ans = 0;
        for(int i = 0; i <= 5; ++i){
            for(int j = 0; j <= 5 - i; ++j){
                for(int k = 0; k <= 5 - i - j; ++k){
                    ans = max(ans, (a + i) * (b + j) * (c + k));
                }
            }
        }
        cout << ans << '\n';
    }
}
