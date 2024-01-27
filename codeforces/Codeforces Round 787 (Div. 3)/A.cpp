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
        int x, y; cin >> x >> y;
        if(max(0, x - a) + max(0, y - b) <= c) cout << "YES\n";
        else cout << "NO\n";
    }
}
