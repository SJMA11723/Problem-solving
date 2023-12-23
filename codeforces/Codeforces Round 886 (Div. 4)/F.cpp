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
        int cub[n + 1] = {};
        int cnt[n + 1] = {};
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            if(x <= n) cnt[x]++;
        }

        for(int x = 1; x <= n; ++x){
            if(!cnt[x]) continue;
            for(int j = x; j <= n; j += x) cub[j] += cnt[x];
        }

        int ans = 0;
        for(int i = 1; i <= n; ++i) ans = max(ans, cub[i]);
        cout << ans << '\n';
    }
}
