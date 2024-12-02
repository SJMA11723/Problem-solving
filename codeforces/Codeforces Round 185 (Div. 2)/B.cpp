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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    long double p = 1 - (long double)a / b;
    long double q = 1 - (long double)c / d;
    cout << fixed << setprecision(7) <<  1 / (1 - p * q) * a / b << '\n';
}
