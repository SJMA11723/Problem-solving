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
        int n, m; cin >> n >> m;
        int ans[n];
        fill(ans, ans + n, -1);
        int cur_idx = n - 1;
        bool recent[n + m] = {};
        for(int i = 0; i < m; ++i){
            int x; cin >> x; x--;
            if(recent[x]) continue;
            else ans[cur_idx--] = i + 1;
            recent[x] = true;
        }

        for(int i = 0; i < n; ++i) cout << ans[i] << " \n"[i + 1 == n];
    }
}
