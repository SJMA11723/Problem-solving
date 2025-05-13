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
        int n; cin >> n;
        int ans = 0, pending = 0;
        bool ok = false;
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            if(x){
                if(ok) ans += pending;
                pending = 0;
                ok = true;
            } else pending++;
        }
        cout << ans << '\n';
    }
}
