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
    int n, m; cin >> n >> m;
    vector<int> graph[n];
    int deg[n] = {}, max_deg = 0, s = 0;
    for(int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
        deg[a]++;
        deg[b]++;
        if(deg[a] > max_deg){
            max_deg = deg[a];
            s = a;
        }

        if(deg[b] > max_deg){
            max_deg = deg[b];
            s = b;
        }
    }

    queue<int> q;
    q.push(s);
    bool vis[n] = {};
    vis[s] = true;

    while(q.size()){
        int cur = q.front();
        q.pop();

        for(int v : graph[cur]){
            if(vis[v]) continue;
            cout << cur + 1 << ' ' << v + 1 << '\n';
            q.push(v);
            vis[v] = true;
        }
    }
}
