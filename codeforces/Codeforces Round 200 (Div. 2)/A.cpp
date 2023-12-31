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
    int n; cin >> n; n *= 2;
    int ans = 1;
    char c, ant = 0;
    for(int i = 0; i < n; ++i){
        cin >> c;
        ans += c == ant;
        ant = c;
    }
    cout << ans << '\n';
}
