/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int di[4] = {0, 0, 1, -1};
int dj[4] = {1, -1, 0, 0};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int r, c; cin >> r >> c;
    char mat[r][c];
    for(int i = 0; i < r; ++i)
        for(int j = 0; j < c; ++j) cin >> mat[i][j];

    bool ok = true;
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            if(mat[i][j] != 'W') continue;

            for(int k = 0; k < 4; ++k){
                int ni = i + di[k];
                int nj = j + dj[k];
                if(ni < 0 || nj < 0 || ni >= r || nj >= c || mat[ni][nj] == 'W') continue;
                if(mat[ni][nj] == 'S') ok = false;
                mat[ni][nj] = 'D';
            }
        }
    }

    if(!ok) cout << "No\n";
    else {
        cout << "Yes\n";
        for(int i = 0; i < r; ++i, cout << '\n')
            for(int j = 0; j < c; ++j) cout << mat[i][j];
    }
}
