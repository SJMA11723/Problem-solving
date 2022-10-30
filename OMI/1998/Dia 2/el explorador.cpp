#include <bits/stdc++.h>

using namespace std;

int iniM, iniN, finM, finN, n, m;
int mat[51][51];
bool visitado[51][51];

int dir_i[4] = {1, 0, -1, 0}, dir_j[4] = {0, 1, 0, -1};

struct pos{
    int i, j;
    int pasos;

    pos(int ni, int nj, int p){
        i = ni;
        j = nj;
        pasos = p;
    }
};

int BFS(){
    queue<pos> cola;
    pos p(iniN, iniM, 1);
    cola.push(p);

    while(!cola.empty()){
        pos act = cola.front();
        cola.pop();

        for(int k = 0; k < 4; ++k){
            int ni = act.i + dir_i[k];
            int nj = act.j + dir_j[k];

            if(0 <= ni && 0 <= nj && ni < n && nj < m &&
            !mat[ni][nj] && !visitado[ni][nj]){
                if(ni == finN && nj == finM) return act.pasos + 1;
                visitado[ni][nj] = true;
                pos np(ni, nj, act.pasos + 1);
                cola.push(np);
            }
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> mat[i][j];
        }
    }

    cin >> iniN >> iniM;
    cin >> finN >> finM;

    visitado[iniN][iniM] = true;

    cout << BFS();

    return 0;
}
