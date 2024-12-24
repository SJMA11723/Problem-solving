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
        int p[n];
        for(int &x : p){
            cin >> x;
            x--;
        }
        int vis[n] = {};
        int ans = 3;
        for(int i = 0; i < n; ++i){
            if(vis[i]) continue;
            int cnt = 0, cur = i;
            while(!vis[cur]){
                cnt++;
                vis[cur] = true;
                cur = p[cur];
            }
            ans = min(ans, cnt);
        }

        cout << ans << '\n';
    }
}
