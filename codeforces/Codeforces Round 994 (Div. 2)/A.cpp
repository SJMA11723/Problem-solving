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
        int ans = 0, prv = 0;
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            if(i && !x && prv) ans++;
            prv = x;
        }
        if(prv) ans++;
        cout << min(ans, 2) << '\n';
    }
}
