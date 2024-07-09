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
        int w, d, h; cin >> w >> d >> h;
        int a, b, f, g;
        cin >> a >> b >> f >> g;
        cout << min({g + h + abs(f - a) + b, d - g + h + abs(f - a) + d - b, /// por frente o atras
                     f + h + abs(g - b) + a, w - f + h + abs(g - b) + w - a ///por los lados
                     }) << '\n';
    }
}
