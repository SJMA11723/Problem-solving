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
        vector<int> graph[n];
        for(int i = 0; i < m; ++i){
            int a, b; cin >> a >> b;
            a--, b--;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        queue<int> q;
        bool chosen[n] = {};
        bool vis[n] = {};
        q.push(0);
        vis[0] = true;
        while(q.size()){
            int u = q.front();
            q.pop();

            for(int v : graph[u]){
                if(vis[v]) continue;
                chosen[v] = !chosen[u];
                q.push(v);
                vis[v] = true;
            }
        }

        int cnt_chosen = 0;
        for(int i = 0; i < n; ++i) cnt_chosen += chosen[i];

        cout << min(cnt_chosen, n - cnt_chosen) << '\n';
        for(int i = 0; i < n; ++i){
            if(cnt_chosen <= n / 2 && chosen[i]) cout << i + 1 << ' ';
            else if(cnt_chosen > n / 2 && !chosen[i]) cout << i + 1 << ' ';
        }
        cout << '\n';
    }
}
