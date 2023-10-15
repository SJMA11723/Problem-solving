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
    int n; cin >> n;
    string from, to;
    cin >> from >> to;
    int ans = 0;
    for(int i = 0; i < n; ++i)
        ans += min( abs(from[i]- to[i]), 26 - abs(from[i]- to[i]));
    cout << ans << '\n';
}
