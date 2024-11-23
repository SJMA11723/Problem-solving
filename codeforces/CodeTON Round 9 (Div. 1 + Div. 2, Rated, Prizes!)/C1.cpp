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
    int t; cin >> t;
    while(t--){
        int64_t x, m;
        cin >> x >> m;
        int ans = 0;
        for(int i = 1; i <= min(2 * x, m); ++i)
            if((x ^ i) && (i % (x ^ i) == 0 || x % (x ^ i) == 0)) ans++;
        cout << ans << '\n';
    }
}
