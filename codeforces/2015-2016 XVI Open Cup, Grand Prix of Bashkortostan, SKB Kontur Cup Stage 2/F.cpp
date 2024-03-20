/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 300

using namespace std;

struct pos{
    int from;
    int64_t c;
    const bool operator<(const pos &b)const{
        return c > b.c;
    }
};

int64_t dijkstra(int a, int n, int adj[][300]){
    int dist[MAXN];
    bool vis[MAXN];
    fill(dist, dist + MAXN, INT_MAX);
    memset(vis, 0, sizeof(vis));

    int prev[n], branch[n];
    prev[a] = a;
    branch[a] = 0;
    int cnt = 0;

    priority_queue<pos> q;
    q.push(pos{a, 0});
    dist[a] = 0;

    while(!q.empty()){
        pos act = q.top();
        q.pop();

        if(vis[act.from]) continue;
        vis[act.from] = true;
        branch[act.from] = prev[act.from] == a ? cnt++ : branch[prev[act.from]];

        for(int v = 0; v < n; ++v){
            if(adj[act.from][v] == -1 || dist[v] < dist[act.from] + adj[act.from][v]) continue;

            dist[v] = dist[act.from] + adj[act.from][v];
            prev[v] = act.from;
            q.push(pos{v, dist[v]});
        }
    }


    int ans = INT_MAX;
    for(int u = 0; u < n; ++u){
        for(int v = 0; v < n; ++v){
            if(!vis[u] || !vis[v] || adj[u][v] == -1 || branch[u] == branch[v] ||
               (u == a && prev[v] == a) || (v == a && prev[u] == a)) continue;

            ans = min(ans, dist[u] + adj[u][v] + dist[v]);
        }
    }


    return ans == INT_MAX ? -1 : ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int adj[n][300];
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> adj[i][j];
            if(i == j) adj[i][j] = -1;
        }
    }

    for(int i = 0; i < n; ++i) cout << dijkstra(i, n, adj) << '\n';
}
