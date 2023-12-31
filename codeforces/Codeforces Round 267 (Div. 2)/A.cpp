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
    int ans = 0, n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        int a, b; cin >> a >> b;
        ans += a + 1 < b;
    }
    cout << ans << '\n';
}
