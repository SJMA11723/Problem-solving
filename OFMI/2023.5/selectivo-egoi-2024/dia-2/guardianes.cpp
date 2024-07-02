/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

void bfs(int s, vector<int> graph[], int n, int dist[]){
    fill(dist, dist + n + 1, INT_MAX);

    queue<int> q;
    q.push(s);
    dist[s] = 0;

    while(q.size()){
        int act = q.front();
        q.pop();

        for(int v : graph[act]){
            if(dist[v] != INT_MAX) continue;
            dist[v] = dist[act] + 1;
            q.push(v);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    int x, y, z; cin >> x >> y >> z;
    vector<int> graph[n + 1];
    for(int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int dist_1[n + 1];
    int dist_2[n + 1];
    int dist_n[n + 1];

    bfs(1, graph, n, dist_1);
    bfs(2, graph, n, dist_2);
    bfs(n, graph, n, dist_n);

    long long ans = 1ll*x * dist_1[n] + 1ll*y * dist_2[n];

    for(int i = 1; i <= n; ++i)
        ans = min(ans, 1ll*x * dist_1[i] + 1ll*y * dist_2[i] + 1ll*z * dist_n[i]);

    cout << ans << '\n';
}
