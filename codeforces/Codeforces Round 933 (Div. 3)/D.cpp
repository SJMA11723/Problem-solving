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
        int n, m, x; cin >> n >> m >> x;
        x--;
        pair<int, char> moves[m];
        for(auto &p : moves) cin >> p.first >> p.second;

        bool vis[n][m + 1];
        memset(vis, 0, sizeof(vis));
        queue<pair<int, int>> q;
        q.push({x, 0});
        vis[x][0] = 1;
        while(q.size()){
            int u = q.front().first;
            int nthrow = q.front().second;
            q.pop();

            if(nthrow == m) continue;

            int d = moves[nthrow].first;
            char c = moves[nthrow].second;

            if(c == '0'){
                int v = (u + d) % n;
                if(!vis[v][nthrow + 1]){
                    vis[v][nthrow + 1] = true;
                    q.push({v, nthrow + 1});
                }
            } else if(c == '1'){
                int v = (u - d + n) % n;
                if(!vis[v][nthrow + 1]){
                    vis[v][nthrow + 1] = true;
                    q.push({v, nthrow + 1});
                }
            } else {
                int v = (u + d) % n;
                if(!vis[v][nthrow + 1]){
                    vis[v][nthrow + 1] = true;
                    q.push({v, nthrow + 1});
                }

                v = (u - d + n) % n;
                if(!vis[v][nthrow + 1]){
                    vis[v][nthrow + 1] = true;
                    q.push({v, nthrow + 1});
                }
            }
        }

        vector<int> ans;
        for(int i = 0; i < n; ++i)
            if(vis[i][m]) ans.push_back(i + 1);

        cout << ans.size() << '\n';
        for(int i = 0; i < ans.size(); ++i) cout << ans[i] << " \n"[i + 1 == ans.size()];
    }
}
