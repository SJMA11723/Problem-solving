/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct pos{
    int i, j;
    int pasos;
};

int n, m;
int dir_i[4] = {0, 0, 1, -1}, dir_j[4] = {1, -1, 0 ,0};
char mapa[2000][2000];
bool visitado[2000][2000];
vector<pos> guardias;

int bfs(){
    int ans = 0;
    queue<pos> q;
    for(pos &g : guardias){
        q.push(g);
        visitado[g.i][g.j] = true;
    }

    while(q.size()){
        pos act = q.front();
        q.pop();

        ans = max(ans, act.pasos);

        for(int k = 0; k < 4; ++k){
            int ni = act.i + dir_i[k];
            int nj = act.j + dir_j[k];
            if(ni < 0 || nj < 0 || ni >= n || nj >= m || visitado[ni][nj] || mapa[ni][nj] == '#') continue;
            q.push({ni, nj, act.pasos + 1});
            visitado[ni][nj] = true;
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> mapa[i][j];
            if(mapa[i][j] == 'G'){
                guardias.push_back({i, j, 0});
            }
        }
    }

    cout << bfs() << '\n';
}
