#include <bits/stdc++.h>

using namespace std;

void dfs(int u, vector<int> tree[], int &ud, int &maxd, int d = 1, int p = -1){
    if(d > maxd){
        ud = u;
        maxd = d;
    }

    for(int v : tree[u]){
        if(v == p) continue;
        dfs(v, tree, ud, maxd, d + 1, u);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> graph[n];
        for(int i = 1; i < n; ++i){
            int a, b; cin >> a >> b;
            a--, b--;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        int u, v, d = -1;
        dfs(0, graph, u, d);
        dfs(u, graph, v, d);

        bool dp[d + 1];
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= d; ++i) dp[i] = !dp[i - 1] || !dp[i - 2];
        if(dp[d]) cout << "Go8\n";
        else cout << "Neodoomer\n";
    } 
}