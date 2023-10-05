/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int n;
bool visitado[25][25];
char mat[25][25];
string str;

///^>v<

void dfs(int i, int j, int idx, int dir){
    if(i < 0 || j < 0 || i >= n || j >= n || visitado[i][j]) return;
    visitado[i][j] = true;

    mat[i][j] = idx < str.size() ? str[idx] : '#';
    //cout << i << ' ' << j << ' ' << str[idx] << ' ' << dir << '\n';

    if(dir == 3){ /// <
        if(j == 0) return;
        if(visitado[i][j - 1]){
            dfs(i + 1, j, idx + 1, 3);
            return;
        }
        dfs(i, j - 1, idx + 1, 0);
    } else if(dir == 0){ /// ^
        if(i == 0) return;
        if(visitado[i - 1][j]){
            dfs(i, j - 1, idx + 1, 0);
            return;
        }
        dfs(i - 1, j, idx + 1, 1);
    } else if(dir == 1){ /// >
        if(j + 1 == n) return;
        if(visitado[i][j + 1]){
            dfs(i - 1, j, idx + 1, 1);
            return;
        }
        dfs(i, j + 1, idx + 1, 2);
    } else { /// v
        if(i + 1 == n) return;
        if(visitado[i + 1][j]){
            dfs(i, j + 1, idx + 1, 2);
            return;
        }
        dfs(i + 1, j, idx + 1, 3);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> str;

    dfs(n / 2, n / 2, 0, 0);

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(mat[i][j] == '#') continue;
            cout << mat[i][j];
        }
    }
    cout << '\n';
}
