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
        int l, r, x; cin >> l >> r >> x;
        int a, b; cin >> a >> b;

        if(a == b){
            cout << "0\n";
            continue;
        }

        if(r - l < x){
            cout << "-1\n";
            continue;
        }

        if(abs(a - b) >= x){
            cout << "1\n";
            continue;
        }

        int ans = INT_MAX;

        if(a - l >= x){
            if(b - l >= x) ans = min(ans, 2);
            if(r - b >= x) ans = min(ans, 3);
        }

        if(r - a >= x){
            if(r - b >= x) ans = min(ans, 2);
            if(b - l >= x) ans = min(ans, 3);
        }

        cout << (ans == INT_MAX ? -1 : ans) << '\n';
    }
}
