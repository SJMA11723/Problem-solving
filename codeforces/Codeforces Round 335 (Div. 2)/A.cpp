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
    int a, b, c; cin >> a >> b >> c;
    int x, y, z; cin >> x >> y >> z;
    int ans = 0;
    if(a - x > 0) ans += (a - x) / 2;
    else ans += a - x;
    if(b - y > 0) ans += (b - y) / 2;
    else ans += b - y;
    if(c - z > 0) ans += (c - z) / 2;
    else ans += c - z;

    cout << (ans >= 0 ? "Yes\n" : "No\n");
}
