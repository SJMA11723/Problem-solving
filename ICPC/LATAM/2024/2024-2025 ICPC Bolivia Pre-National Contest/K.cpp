#include <bits/stdc++.h>

using namespace std;

int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, 1, -1};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    while(cin >> n){
        cin >> m;
        char mat[n][m];
        int a, b;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                cin >> mat[i][j];
                if(mat[i][j] == 'S'){
                    a = i;
                    b = j;
                }
            }
        }

        queue<pair<int, int>> q;
        bool vis[n][m];
        memset(vis, 0, sizeof(vis));
        q.push({a, b});
        vis[a][b];
        int ans = 0;
        while(q.size()){
            int i, j;
            tie(i, j) = q.front();
            q.pop();

            if('1' <= mat[i][j] && mat[i][j] <= '9') ans += mat[i][j] - '0';

            bool trap = false;
            for(int k = 0; k < 4; ++k){
                int ni = i + di[k];
                int nj = j + dj[k];
                if(ni < 0 || nj < 0 || ni >= n || nj >= m || mat[ni][nj] != 'T') continue;
                trap = true;
            }
            if(trap) continue;

            for(int k = 0; k < 4; ++k){
                int ni = i + di[k];
                int nj = j + dj[k];
                if(ni < 0 || nj < 0 || ni >= n || nj >= m || mat[ni][nj] == '#' || vis[ni][nj]) continue;
                vis[ni][nj] = true;
                q.push({ni, nj});
            }
        }
        cout << ans << '\n';
    }
}
