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
    int k2, k3, k5, k6;
    cin >> k2 >> k3 >> k5 >> k6;
    cout << 256 * min({k2, k5, k6}) + 32 * min(k3, k2 - min({k2, k5, k6})) << '\n';
}
