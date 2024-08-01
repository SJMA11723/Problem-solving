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
    char c;
    int h1, m1; cin >> h1 >> c >> m1;
    int h2, m2; cin >> h2 >> c >> m2;

    int minutes = (h2 + h1) * 60 + m2 + m1;
    cout << setw(2) << setfill('0') << minutes / 2 / 60 << c << setw(2) << minutes / 2 % 60 << '\n';
}
