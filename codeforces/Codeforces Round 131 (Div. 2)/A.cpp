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
    int n, m; cin >> n >> m;
    int ans = 0;
    for(int b = 0; b <= m; ++b)
    for(int a = 0; a <= n; ++a)
    if(a * a + b == m && a + b * b == n) ans++;
    cout << ans << '\n';
}

