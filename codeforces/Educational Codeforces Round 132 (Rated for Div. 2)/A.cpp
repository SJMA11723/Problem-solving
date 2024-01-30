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
        int x, a, b, c; cin >> x >> a >> b >> c;
        if(x == 1){
            if((a == 2 && b == 3) || (a == 3 && c == 2)) cout << "YES\n";
            else cout << "NO\n";
        } else if(x == 2){
            if((b == 1 && a == 3) || (b == 3 && c == 1)) cout << "YES\n";
            else cout << "NO\n";
        } else {
            if((c == 1 && a == 2) || (c == 2 && b == 1)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
