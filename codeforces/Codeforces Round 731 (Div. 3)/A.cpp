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
        int x1, x2, x3, y1, y2, y3;
        cin >> x1 >> y1
            >> x2 >> y2
            >> x3 >> y3;
        if((x1 == x2 && x2 == x3 && min(y1, y2) <= y3 && y3 <= max(y1, y2)) ||
           (y1 == y2 && y2 == y3 && min(x1, x2) <= x3 && x3 <= max(x1, x2))) cout << abs(x1 - x2) + abs(y1 - y2) + 2 << '\n';
        else cout << abs(x1 - x2) + abs(y1 - y2) << '\n';
    }
}
