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
    long long n, m; cin >> n >> m;
    long long ans = (n / 5) * (m / 5);
    for(int i = 1; i < 5; ++i){
        ans += (n / 5 + (i <= n % 5)) * (m / 5 + (5 - i <= m % 5));
    }
    cout << ans << '\n';
}
