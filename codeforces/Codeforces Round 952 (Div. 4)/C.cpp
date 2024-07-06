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
        int n; cin >> n;
        int ans = 0;
        int64_t sum = 0, maxi = -1;
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            sum += x;
            maxi = max(maxi, 1ll*x);
            if(sum == 2 * maxi) ans++;
        }
        cout << ans << '\n';
    }
}
