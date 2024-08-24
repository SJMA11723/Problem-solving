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
    long double a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    if(b * d * f != a * c * e){
        cout << "-1\n";
        return 0;
    }

    long double x = 1, y = e / f, z = c * y / d;

    if(x + y > z && x + z > y && y + z > x) cout << "1\n";
    else cout << "-1\n";
}
