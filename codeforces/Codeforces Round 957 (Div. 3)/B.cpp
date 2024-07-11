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
        int n, k; cin >> n >> k;

        int64_t ans = 0;
        int maxi = 0;
        for(int i = 0; i < k; ++i){
            int x; cin >> x;
            maxi = max(maxi, x);
            if(x == 1) ans++;
            else ans += 2 * x - 1;
        }
        if(maxi == 1) ans--;
        else ans -= 2 * maxi - 1;
        cout << ans << '\n';
    }
}
