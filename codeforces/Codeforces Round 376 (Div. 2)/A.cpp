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
    string str; cin >> str;
    int ans = min(str[0] - 'a', 26 - str[0] + 'a');
    for(int i = 1; i < str.size(); ++i) ans += min(abs(str[i] - str[i - 1]), 26 - abs(str[i] - str[i - 1]));
    cout << ans << '\n';
}
