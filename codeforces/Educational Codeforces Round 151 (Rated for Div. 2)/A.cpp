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
        int n, k, x;
        cin >> n >> k >> x;
        int ans = -1, cnt;
        for(int i = 1; i <= k; ++i){
            if(i == x) continue;
            for(int c = 1; i * c <= n; ++c){
                if(n - i * c <= k && n - i * c != x){
                    ans = i;
                    cnt = c;
                    i = n + 1;
                    break;
                }
            }
        }
        if(ans == -1) cout << "NO\n";
        else {
            cout << "YES\n" << cnt + (n - ans * cnt != 0) << '\n';
            for(int i = 0; i < cnt; ++i) cout << ans << ' ';
            if(n - ans * cnt) cout << n - ans * cnt;
            cout << '\n';
        }
    }
}
