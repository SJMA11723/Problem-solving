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
    int ans = 0, min_o = INT_MAX;
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        if(x % 2) min_o = min(min_o, x);
        ans += x;
    }
    if(ans % 2 == 0) ans = (ans - min_o) * (min_o != INT_MAX);
    cout << ans << '\n';
}
