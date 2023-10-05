/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int r, c;
char mapa[1001][1001];
bool visitado[1001][1001];
int dist[1001][1001];
int dir_i[4] = {0, 1, 0, -1};
int dir_j[4] = {-1, 0, 1, 0};
char dir[4] = {'L', 'D', 'R', 'U'};

struct pos{
    int i, j;
    int pasos;
};

void bfs(int a, int b){
    queue<pos> q;
    visitado[a][b] = true;
    q.push(pos{a, b, 0});
    while(q.size()){
        pos act = q.front();
        q.pop();

        dist[act.i][act.j] = act.pasos;

        for(int k = 0; k < 4; ++k){
            int ni = act.i + dir_i[k];
            int nj = act.j + dir_j[k];

            if(ni < 1 || nj < 1 || nj > c || ni > r ||
               mapa[ni][nj] == '#' || mapa[ni][nj] == 'X' || visitado[ni][nj]) continue;
            visitado[ni][nj] = true;
            q.push(pos{ni, nj, act.pasos + 1});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> r >> c;
    int ie, je;
    for(int i = 1; i <= r; ++i)
        for(int j = 1; j <= c; ++j){
            cin >> mapa[i][j];
            if(mapa[i][j] == 'E'){
                ie = i;
                je = j;
            }
        }

    bfs(ie, je);

    int q; cin >> q;
    while(q--){
        int i, j;
        cin >> i >> j;
        if(mapa[i][j] == '#') cout << "W\n";
        else if(mapa[i][j] == 'X') cout << "X\n";
        else if(mapa[i][j] == 'E') cout << "E\n";
        else if(!visitado[i][j]) cout << "?\n";
        else {
            int d = 1e9;
            char direccion;
            for(int k = 0; k < 4; ++k){
                int ni = i + dir_i[k];
                int nj = j + dir_j[k];

                if(ni < 1 || nj < 1 || nj > c || ni > r) continue;
                if(mapa[ni][nj] == '#' || mapa[ni][nj] == 'X') continue;
                if(dist[ni][nj] < d){
                    d = dist[ni][nj];
                    direccion = dir[k];
                }
            }
            cout << direccion << '\n';
        }
    }
}
