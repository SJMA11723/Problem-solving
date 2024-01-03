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
        int n, x, y; cin >> n >> x >> y;
        if(n <= x && 3 * n <= y) cout << "YES\n";
        else if(n <= x) {
            x -= n;
            n -= min(n, y / 3);
            if(n <= x) cout << "YES\n";
            else cout << "NO\n";
        } else cout << "NO\n";
    }
}
