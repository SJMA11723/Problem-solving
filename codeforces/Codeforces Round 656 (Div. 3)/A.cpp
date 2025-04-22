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
        int x, y, z; cin >> x >> y >> z;
        int a = min(x, y);
        int b = min(x, z);
        int c = min(y, z);

        if(x == max(a, b) && y == max(a, c) && z == max(b, c)) cout << "YES\n" << a << ' ' << b << ' ' << c << '\n';
        else cout << "NO\n";
    }
}
