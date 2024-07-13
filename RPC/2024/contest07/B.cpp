/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

//bool vis[1000][1000];

int64_t dfs(int u, vector<int> graph[], int64_t pages[], bool vis[], stack<int> &st, bool save = false){
    if(vis[u]) return 0;
    vis[u] = true;

    if(save) st.push(u);

    int64_t res = pages[u];
    for(int v : graph[u]) res += dfs(v, graph, pages, vis, st, save);
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;

    int64_t pages[n];
    for(int64_t &x : pages) cin >> x;

    vector<int> inv_graph[n];
    int in_deg[n] = {};
    for(int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;
        a--, b--;
        inv_graph[b].push_back(a);
        in_deg[a]++;
    }

    int64_t ans = LLONG_MAX;
    bool vis[n] = {};
    for(int i = 0; i < n; ++i){
        if(in_deg[i]) continue;
        memset(vis, 0, sizeof(vis));

        stack<int> st;

        int64_t cnt = dfs(i, inv_graph, pages, vis, st);

        for(int j = i + 1; j < n; ++j){
            if(in_deg[j]) continue;

            int64_t cnt2 = dfs(j, inv_graph, pages, vis, st, true);
            ans = min(ans, cnt + cnt2);

            while(st.size()){
                vis[st.top()] = false;
                st.pop();
            }
        }
    }

    cout << ans << '\n';
}
