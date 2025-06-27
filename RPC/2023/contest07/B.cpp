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
    int dd, mm, yy, ff, dd2, mm2, yy2;
    cin >> dd >> mm >> yy >> ff >> dd2 >> mm2 >> yy2;
    int diff = (yy2 - yy) * 12 * 30 + (mm2 - mm) * 30 + dd2 - dd;
    cout << (ff - 1 + diff) % 7 + 1 << '\n';
}
