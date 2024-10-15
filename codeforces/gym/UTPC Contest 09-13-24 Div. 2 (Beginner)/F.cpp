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
    int n, m, s, k, g;
    cin >> n >> m >> s >> k >> g;
    vector<int> graph[n + 1];
    for(int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int exits[k];
    for(int &x : exits) cin >> x;

    int ghosts[g];
    for(int &x : ghosts) cin >> x;

    int dist_ghost[n + 1];
    fill(dist_ghost, dist_ghost + n + 1, INT_MAX);
    queue<int> q;
    for(int x : ghosts){
        q.push(x);
        dist_ghost[x] = 0;
    }

    while(q.size()){
        int u = q.front(); q.pop();

        for(int v : graph[u]){
            if(dist_ghost[v] != INT_MAX) continue;

            dist_ghost[v] = dist_ghost[u] + 1;
            q.push(v);
        }
    }

    int dist[n + 1];
    fill(dist, dist + n + 1, INT_MAX);
    /// False: Harry, True: Ghost
    bool first_to_reach[n + 1] = {};
    q.push(s);
    dist[s] = 0;
    while(q.size()){
        int u = q.front(); q.pop();

        if(dist[u] >= dist_ghost[u]) first_to_reach[u] = true;

        for(int v : graph[u]){
            if(dist[v] != INT_MAX) continue;

            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }

    int ans = 0;
    for(int e : exits) if(dist[e] != INT_MAX && !first_to_reach[e]) ans++;
    cout << ans << '\n';
}
