/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int r, c;
int mat[101][101];

struct pos{
    int i, j;
    int n;
    pos(int a, int b, int c) : i(a), j(b), n(c){}

    bool operator<(const pos &b) const {
        return n > b.n;
    }
};

int dir_i[4] = {-1, 0, 1, 0}, dir_j[4] = {0, 1, 0, -1};

int bfs(int i, int j){
    vector<vector<bool>> visitado(r, vector<bool>(c, false));
    priority_queue<pos> cola;
    cola.push(pos(i, j, mat[i][j]));

    vector<pos> recorrido;
    recorrido.push_back(pos(i, j, mat[i][j]));

    while(cola.size()){
        pos act = cola.top();
        cola.pop();

        if(recorrido.back().n < act.n){
            recorrido.push_back(act);
        }

        for(int k = 0; k < 4; ++k){
            int ni = act.i + dir_i[k];
            int nj = act.j + dir_j[k];

            if(0 <= ni && 0 <= nj && ni < r && nj < c && !visitado[ni][nj] && act.n < mat[ni][nj] && recorrido.back().n < mat[ni][nj]){
                visitado[ni][nj] = true;
                cola.push(pos(ni, nj, mat[ni][nj]));
            }
        }
    }

    return recorrido.size();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> r >> c;
    for(int i = 0; i < r; ++i) for(int j = 0; j < c; ++j) cin >> mat[i][j];

    int ans = 0;
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            ans = max(ans, bfs(i, j));
        }
    }
    cout << ans << '\n';
}
