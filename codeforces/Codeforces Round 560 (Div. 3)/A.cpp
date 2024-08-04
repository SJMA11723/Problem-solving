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
    int n, x, y; cin >> n >> x >> y;
    string num; cin >> num;
    reverse(num.begin(), num.end());
    int ans = 0;
    for(int i = 0; i < x; ++i) if(num[i] == '1') ans++;
    if(num[y] == '1') ans--;
    else ans++;
    cout << ans << '\n';
}
