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
    string a, b; cin >> a >> b;
    int ans = 0;
    for(int i = 0; i < n; ++i) ans += min({abs(a[i] - b[i]), a[i] - '0' + '9' - b[i] + 1, b[i] - '0' + '9' - a[i] + 1});
    cout << ans << '\n';
}
