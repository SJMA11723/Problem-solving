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
    long long l, r;
    cin >> l >> r;
    if(r - l + 1 < 3 || (r - l + 1 == 3 && l % 2)) cout << "-1\n";
    else if(l % 2) cout << l + 1 << ' ' << l + 2 << ' ' << l + 3 << '\n';
    else cout << l << ' ' << l + 1 << ' ' << l + 2 << '\n';
}
