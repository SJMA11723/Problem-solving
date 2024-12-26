/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> floyd_warshall(int n, vector<vector<bool>> &adj){
    vector<vector<int>> d(n, vector<int>(n, INT_MAX));
    for(int i = 0; i < n; ++i) d[i][i] = 0;
    for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
    if(adj[i][j]) d[i][j] = adj[i][j];

    for(int k = 0; k < n; ++k){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(d[i][k] == INT_MAX) continue;
                if(d[k][j] == INT_MAX) continue;
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    return d;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        string first; cin >> first;
        int n = first.size();
        vector<vector<bool>> adj(n, vector<bool>(n));
        for(int j = 0; j < n; ++j){
            char c = first[j];
            if(c == 'Y') adj[0][j] = 1;
        }
        for(int i = 1; i < n; ++i)
        for(int j = 0; j < n; ++j){
            char c; cin >> c;
            if(c == 'Y') adj[i][j] = 1;
        }

        vector<vector<int>> d = floyd_warshall(n, adj);

        int id, ans = -1;
        for(int i = 0; i < n; ++i){
            int cnt = 0;
            for(int j = 0; j < n; ++j)
                if(d[i][j] == 2) cnt++;
            if(ans < cnt){
                ans = cnt;
                id = i;
            }
        }

        cout << id << ' ' << ans << '\n';
    }
}
