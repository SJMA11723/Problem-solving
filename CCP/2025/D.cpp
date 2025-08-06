#include <bits/stdc++.h>

using namespace std;

struct edge{
    int to, time;
};

bool dfs(int u, vector<edge> graph[], char vis[], const int MAX_TIME){
    vis[u] = 1;
    for(edge &e : graph[u]){
        if(e.time > MAX_TIME) continue;
        if(vis[e.to]){
            if(vis[e.to] == 1) return true;
            continue;
        }

        if(dfs(e.to, graph, vis, MAX_TIME)) return true;
    }
    vis[u] = 2;
    return false;
}

// has cycle
bool check(int n, vector<edge> graph[], const int MAX_TIME){{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
    char vis[n] = {};
    for(int i = 0; i < n; ++i){
        if(vis[i]) continue;
        if(dfs(i, graph, vis, MAX_TIME)) return true;
    }
    return false;
}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    vector<edge> graph[n];
    for(int i = 1; i <= m; ++i){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back({b, i});
    }

    int l = 1, r = m + 1;
    while(l < r){
        int mid = (l + r) / 2;
        if(check(n, graph, mid)) r = mid;
        else l = mid + 1;
    }
    cout << (l == m + 1 ? -1 : l) << '\n';
}