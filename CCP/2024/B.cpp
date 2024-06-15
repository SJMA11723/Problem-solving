/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define is_on(n, i) ((n) & (1ll << (i)))

using namespace std;

int n, m, a, b;
int mat[50][50];

struct pos{
    int i, j, d;
};

int di[4] = {0, -1, 0, 1};
int dj[4] = {-1, 0, 1, 0};

void bfs(){
    bool vis[50][50];
    memset(vis, 0, sizeof(vis));
    queue<pos> q;
    q.push({a, b, 0});
    vis[a][b] = true;

    while(q.size()){
        pos act = q.front();
        q.pop();

        if(!act.j && !is_on(mat[act.i][act.j], 0)){
            cout << act.d << '\n';
            exit(0);
        }

        if(!act.i && !is_on(mat[act.i][act.j], 1)){
            cout << act.d << '\n';
            exit(0);
        }

        if(act.j == m - 1 && !is_on(mat[act.i][act.j], 2)){
            cout << act.d << '\n';
            exit(0);
        }

        if(act.i == n - 1 && !is_on(mat[act.i][act.j], 3)){
            cout << act.d << '\n';
            exit(0);
        }

        //cout << act.i << ' ' << act.j << ' ' << mat[act.i][act.j] << '\n';

        for(int k = 0; k < 4; ++k){
            int ni = act.i + di[k];
            int nj = act.j + dj[k];

            //cout << ni << ' ' << nj << ' ' << is_on(mat[ni][nj], k) << '\n';

            if(ni < 0 || nj < 0 || ni >= n || nj >= m || vis[ni][nj] || is_on(mat[act.i][act.j], k)) continue;

            q.push({ni, nj, act.d + 1});
            vis[ni][nj] = true;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> a >> b;
    a--, b--;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> mat[i][j];
        }
    }

    bfs();

    cout << "-1\n";
}
