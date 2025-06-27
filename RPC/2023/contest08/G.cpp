/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 501

using namespace std;

typedef long long ll;

int dir_i[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dir_j[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int cost[3][3] = {{1, 2, 3},{8, 0, 4},{7, 6, 5}};
int n, m, A, B, e;
int mat[MAXN][MAXN];
int dist[MAXN][MAXN];
bool visitado[MAXN][MAXN];

struct pos{
    int i, j;
    int c;
    const bool operator<(const pos &b) const{
        return c > b.c;
    }
};

int dijkstra(int a, int b, int e){
    memset(dist, 255 >> 1, sizeof(visitado));
    memset(visitado, 0, sizeof(visitado));

    priority_queue<pos> q;
    q.push(pos{a, b, 0});
    dist[a][b] = 0;
    int res = 0;

    while(!q.empty()){
        pos act = q.top();
        q.pop();

        //cout << "p: " << act.i << ' ' << act.j << ' ' << act.c << '\n';

        if(mat[act.i][act.j]){
            res = max(res, mat[act.i][act.j]);
            continue;
        }

        if(visitado[act.i][act.j]) continue;
        visitado[act.i][act.j] = true;

        for(int k = 0; k < 8; ++k){
            int ni = act.i + dir_i[k];
            int nj = act.j + dir_j[k];
            int c = cost[1 + dir_i[k]][1 + dir_j[k]];

            //cout << c << ' ' << dist[act.i][act.j] << '\n';

            if(ni < 1 || nj < 1 || ni > n || nj > m || dist[ni][nj] < dist[act.i][act.j] + c || e < dist[act.i][act.j] + c) continue;

            dist[ni][nj] = dist[act.i][act.j] + c;
            //cout << c << ' ' << dist[act.i][act.j] << '\n';
            //cout << "Entra: " << ni << ' ' << nj << ' ' << dist[ni][nj] << '\n';
            q.push(pos{ni, nj, dist[ni][nj]});
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> A >> B >> e;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> mat[i][j];
        }
    }

    cout << dijkstra(A, B, e) << '\n';
}
