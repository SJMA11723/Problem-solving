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
        int x; cin >> x;
        int ans = 0;
        for(int i = 1; i < 10; ++i){
            int num = i, cnt = 1;
            while(num < 10000){
                ans += cnt++;
                if(num == x) break;
                num = num * 10 + i;
            }
            if(num == x) break;
        }
        cout << ans << '\n';
    }
}
