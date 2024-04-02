/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 1001

using namespace std;

void dfs(int node, const int forbidden, vector<int> graph[], bool vis[]){
    if(vis[node] || node == forbidden) return;
    vis[node] = true;
    for(int v : graph[node]) dfs(v, forbidden, graph, vis);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    vector<int> inv_graph[n + 1];
    pair<int, int> arr[n + 1];
    for(int i = 1; i <= n; ++i){
        int a, b; cin >> a >> b;
        arr[i] = {a, b};
        inv_graph[a].push_back(i);
        inv_graph[b].push_back(i);
    }

    bool vis1[n + 1], vis2[n + 1], vis3[n + 1];
    for(int i = 1; i <= n; ++i){
        auto [a, b] = arr[i];
        memset(vis1, 0, sizeof(vis1));
        memset(vis2, 0, sizeof(vis2));
        memset(vis3, 0, sizeof(vis3));

        dfs(a, i, inv_graph, vis1);
        dfs(b, i, inv_graph, vis2);
        dfs(i, 0, inv_graph, vis3);

        bool no = true;
        for(int i = 1; i <= n; ++i)
            if(vis1[i] && vis2[i] && vis3[i]) no = false;
        cout << (no ? 'N' : 'Y');
    }
    cout << '\n';
}
