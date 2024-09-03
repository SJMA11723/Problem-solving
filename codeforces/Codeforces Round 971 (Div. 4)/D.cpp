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
        int cnt0 = 0, cnt1 = 0;
        bool ap[2][n + 1];
        memset(ap, 0, sizeof(ap));
        for(int i = 0; i < n; ++i){
            int x, y; cin >> x >> y;
            ap[y][x] = true;
            if(y) cnt1++;
            else cnt0++;
        }

        int64_t ans = 0;
        int cnt = 0;
        for(int i = 0; i <= n; ++i){
            cnt += ap[0][i] && ap[1][i];

            if(i && i < n) ans += (ap[0][i] && ap[1][i - 1] && ap[1][i + 1]) + (ap[1][i] && ap[0][i - 1] && ap[0][i + 1]);
        }
        ans += 1ll * cnt * (n - 2);

        cout << ans << '\n';
    }
}
