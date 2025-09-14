#include <bits/stdc++.h>

using namespace std;

void dfs(int u, vector<int> graph[], int dp[], int p[], int age[]){
    if(dp[u] != INT_MAX) return;
    dp[u] = age[p[u]];
    for(int v : graph[u]){
        dfs(v, graph, dp, p, age);
        dp[u] = min(dp[u], dp[v]);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, q; cin >> n >> m >> q;
    int age[n], p[n], inv_p[n];
    for(int i = 0; i < n; ++i){
        cin >> age[i];
        p[i] = i;
        inv_p[i] = i;
    }

    vector<int> graph[n];
    for(int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[b].push_back(a);
    }

    while(q--){
        char c; cin >> c;
        if(c == 'T'){
            int a, b; cin >> a >> b;
            a--, b--;
            p[inv_p[a]] = b;
            p[inv_p[b]] = a;
            swap(inv_p[a], inv_p[b]);
        } else {
            int u; cin >> u; u--;
            u = inv_p[u];
            if(graph[u].empty()){
                cout << "*\n";
                continue;
            }
            int dp[n];
            fill(dp, dp + n, INT_MAX);
            dfs(u, graph, dp, p, age);

            int ans = INT_MAX;
            for(int v : graph[u]) ans = min(ans, dp[v]);
            cout << ans << '\n';
        }
    }
}
