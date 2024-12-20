/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int64_t>> floyd_warshall(int n, vector<vector<int64_t>> &adj){
    vector<vector<int64_t>> d(n, vector<int64_t>(n, LLONG_MAX));
    for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j){
        if(!adj[i][j] && i != j) continue;
        d[i][j] = adj[i][j];
    }

    for(int k = 0; k < n; ++k){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(d[i][k] == LLONG_MAX) continue;
                if(d[k][j] == LLONG_MAX) continue;
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(d[i][j] == LLONG_MAX) continue;
            for(int k = 0; k < n; ++k){
                if(d[k][k] < 0 && d[i][k] != LLONG_MAX && d[k][j] != LLONG_MAX)
                    d[i][j] = LLONG_MIN;
            }
        }
    }

    return d;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int cnt = 1;
    while(n){
        string names[n];
        vector<vector<int64_t>> adj(n, vector<int64_t>(n));
        for(int i = 0; i < n; ++i){
            cin >> names[i];
            for(int j = 0; j < n; ++j){
                cin >> adj[i][j];
                if(i == j && adj[i][j] > 0) adj[i][j] = 0;
            }
        }

        vector<vector<int64_t>> d = floyd_warshall(n, adj);

        cout << "Case #" << cnt++ << ":\n";
        int q; cin >> q;
        while(q--){
            int u, v; cin >> u >> v;
            if(d[u][v] == LLONG_MIN) cout << "NEGATIVE CYCLE\n";
            else {
                cout << names[u] << '-' << names[v] << ' ';
                if(d[u][v] == LLONG_MAX) cout << "NOT REACHABLE\n";
                else cout << d[u][v] << '\n';
            }
        }

        cin >> n;
    }
}
