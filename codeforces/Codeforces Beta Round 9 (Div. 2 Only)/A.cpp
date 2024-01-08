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
    int y, w; cin >> y >> w;
    int a = 6 - max(y, w) + 1;
    cout << a / gcd(a, 6) << '/' << 6 / gcd(a, 6) << '\n';
}
