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
    int n, k; cin >> n >> k;
    int ans = 0, time = k;
    for(int i = 1; i <= n && time + i * 5 <= 240; ++i, ans++) time += i * 5;
    cout << ans << '\n';
}
