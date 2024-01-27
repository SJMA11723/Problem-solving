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
        int ans = 0;
        for(int i = 0; i < 10; ++i){
            for(int j = 0; j < 10; ++j){
                char c; cin >> c;
                if(c != 'X') continue;
                ans += min({i + 1, 10 - i, j + 1, 10 - j});
            }
        }
        cout << ans << '\n';
    }
}
