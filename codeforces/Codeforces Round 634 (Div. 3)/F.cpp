/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int n, m;

int id(int i, int j){
    return i * m + j;
}

pair<int, int> coord(int _id){
    return {_id / m, _id % m};
}

void dfs(int u, vector<int> graph[], char vis[], vector<int> &cycle, int &init){
    if(vis[u] == 2) return;
    if(vis[u] == 1){
        init = u;
        return;
    }

    vis[u] = 1;
    dfs(graph[u][0], graph, vis, cycle, init);
    if(init != -1){
        cycle.push_back(u);
        if(u == init) init = -1;
    }

    vis[u] = 2;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        cin >> n >> m;
        char color[n][m];
        for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
        cin >> color[i][j];

        vector<int> graph[n * m], inv_graph[n * m];
        for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j){
            char d; cin >> d;
            int u = id(i, j), v;
            if(d == 'U') v = id(i - 1, j);
            else if(d == 'D') v = id(i + 1, j);
            else if(d == 'L') v = id(i, j - 1);
            else if(d == 'R') v = id(i, j + 1);

            graph[u].push_back(v);
            inv_graph[v].push_back(u);
        }

        int max_robots = 0, max_black = 0;
        char vis[n * m] = {};
        bool visbfs[n * m] = {};
        for(int i = 0; i < n * m; ++i){
            if(vis[i]) continue;
            vector<int> cycle;
            int init = -1;
            dfs(i, graph, vis, cycle, init);

            reverse(cycle.begin(), cycle.end());
            init = cycle.back();

            max_robots += cycle.size();

            bool visb[cycle.size()] = {};


            queue<pair<int, int>> q;
            q.push({init, 0});
            while(q.size()){
                int u = q.front().first;
                int pos = q.front().second;
                q.pop();

                int x, y;
                tie(x, y) = coord(u);
                if(color[x][y] == '0') visb[pos] = true;

                for(int v : inv_graph[u]){
                    if(visbfs[v]) continue;
                    visbfs[v] = true;
                    vis[v] = 2;
                    q.push({v, (pos + 1) % cycle.size()});
                }
            }

            for(int j = 0; j < cycle.size(); ++j) max_black += visb[j];
        }

        cout << max_robots << ' ' << max_black << '\n';
    }
}
