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
    int x1, y1, x2, y2, x, y;
    cin >> x1 >> y1 >> x2 >> y2 >> x >> y;
    if(abs(x1 - x2) % x == 0 && abs(y1 - y2) % y == 0 && abs(x1 - x2) / x % 2 == abs(y1 - y2) / y % 2) cout << "YES\n";
    else cout << "NO\n";
}
