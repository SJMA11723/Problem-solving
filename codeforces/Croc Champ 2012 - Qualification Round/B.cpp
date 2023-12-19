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
    int a, b, m, r0;
    cin >> a >> b >> m >> r0;
    a %= m;
    b %= m;
    int idx[m] = {};
    int ans;
    int r = (a * r0 + b) % m;
    int cnt = 1;
    do{
        idx[r] = cnt++;
        r = (a * r + b) % m;
    }while(!idx[r]);
    cout << cnt - idx[r] << '\n';
}
