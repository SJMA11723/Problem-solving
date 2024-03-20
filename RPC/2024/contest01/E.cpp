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
    double x, y;
    cin >> x >> y;
    cout << fixed << setprecision(8) << (100 - y) * x / ((100 - x) * y) << '\n';
}
