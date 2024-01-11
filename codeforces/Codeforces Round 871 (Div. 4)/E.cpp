/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int n, m;
int mat[1000][1000];
bool vis[1000][1000];
int dir_i[4] = {1, -1, 0, 0}, dir_j[4] = {0, 0, 1, -1};

int dfs(int i, int j){
    vis[i][j] = true;
    int res = 0;
    for(int k = 0; k < 4; ++k){
        int ni = i + dir_i[k];
        int nj = j + dir_j[k];

        if(ni < 0 || nj < 0 || ni >= n || nj >= m || !mat[ni][nj] || vis[ni][nj]) continue;
        res += dfs(ni, nj);
    }
    return mat[i][j] + res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                cin >> mat[i][j];
            }
        }

        memset(vis, 0, sizeof(vis));
        int ans = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(vis[i][j] || !mat[i][j]) continue;
                ans = max(ans, dfs(i, j));
            }
        }
        cout << ans << '\n';
    }
}
