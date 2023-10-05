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
        int a, x, ans = 0;
        cin >> a;
        for(int i = 0; i < 3; ++i){
            cin >> x;
            if(a < x) ans++;
        }
        cout << ans << '\n';
    }
}
