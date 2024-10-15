/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define lsb(S) ((S) & -(S))
#define is_on(S, i) ((S) & (1ll << (i)))

using namespace std;

int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, 1, -1};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    char mat[n][m];
    map<pair<int, int>, int> candies;
    int is, js, idx = 0;
    for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j){
        cin >> mat[i][j];
        if(mat[i][j] == 'S'){
            is = i;
            js = j;
        } else if(mat[i][j] == 'C') candies[{i, j}] = idx++;
    }

    bool vis[n][m][9][1 << 8];
    int dist[n][m][9][1 << 8];
    memset(vis, 0, sizeof(vis));
    queue<tuple<int, int, short, short>> q;
    q.push({is, js, 0, 0});
    vis[is][js][0][0] = true;
    dist[is][js][0][0] = 0;

    while(q.size()){
        int i, j;
        short c, vc;
        tie(i, j, c, vc) = q.front(); q.pop();

        if(mat[i][j] == 'E'){
            cout << dist[i][j][c][vc] << '\n';
            return 0;
        }

        for(int k = 0; k < 4; ++k){
            int ni = i + di[k];
            int nj = j + dj[k];
            short nc = c;
            short nvc = vc;

            if(ni < 0 || nj < 0 || ni >= n || nj >= m || mat[ni][nj] == 'P') continue;
            if(mat[ni][nj] == 'J') nc--;
            else if(mat[ni][nj] == 'C' && !is_on(nvc, (candies[{ni, nj}]) ) ){
                nvc |= (1 << candies[{ni, nj}]);
                nc++;
            }

            if(nc < 0 || vis[ni][nj][nc][nvc]) continue;

            q.push({ni, nj, nc, nvc});
            vis[ni][nj][nc][nvc] = true;
            dist[ni][nj][nc][nvc] = dist[i][j][c][vc] + 1;
        }
    }

    cout << "SPOOKED!\n";
}
