/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int r, c;
char board[19][19];
bool visitado[19][19];
bool libres[19][19];
int dir_i[4] = {0, 0, 1, -1}, dir_j[4] = {1, -1, 0, 0};

int dfs(int i, int j){
    if(visitado[i][j]) return 0;
    visitado[i][j] = true;

    int res = 0;
    for(int k = 0; k < 4; ++k){
        int ni = i + dir_i[k];
        int nj = j + dir_j[k];

        if(ni < 0 || nj < 0 || r <= ni || c <= nj ||
           visitado[ni][nj] || board[ni][nj] == 'B') continue;
        if(board[ni][nj] == '.'){
            if(!libres[ni][nj]) res++;
            libres[ni][nj] = true;
        } else {
            res += dfs(ni, nj);
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int t;
    cin >> t;

    for(int tt = 1; tt <= t; ++tt){
        memset(visitado, 0, sizeof(visitado));
        cin >> r >> c;
        for(int i = 0; i < r; ++i) cin >> board[i];

        bool ok = false;
        for(int i = 0; i < r; ++i){
            for(int j = 0; j < c; ++j){
                if(board[i][j] != 'W') continue;
                memset(libres, 0, sizeof(libres));
                if(dfs(i, j) == 1) ok = true;
            }
        }
        cout << "Case #" << tt << ": ";
        ok ? cout << "YES\n" : cout << "NO\n";
    }

}
