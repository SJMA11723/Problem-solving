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
        int P[n];
        for(int &x : P){
            cin >> x;
            x--;
        }

        string s; cin >> s;

        int ans[n];
        bool vis[n] = {};
        for(int i = 0; i < n; ++i){
            if(vis[P[i]]) continue;

            int cur = P[i];
            int cnt = !(s[cur] - '0');
            vis[cur] = true;
            while(P[cur] != P[i]){
                cur = P[cur];
                cnt += !(s[cur] - '0');
                vis[cur] = true;
            }

            cur = P[i];
            ans[cur] = cnt;
            while(P[cur] != P[i]){
                cur = P[cur];
                ans[cur] = cnt;
            }
        }

        for(int i = 0; i < n; ++i) cout << ans[i] << " \n"[i + 1 == n];
    }
}
