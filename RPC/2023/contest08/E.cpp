/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct pos{
    int t;
    int c;
};

pos mat[27][27];
bool vis1[27][27], vis2[27][27];
int n, maxT[28], maxC[28];
int dir_i[4] = {1, -1, 0, 0}, dir_j[4] = {0, 0, 1, -1};

int dfs1(int i, int j, int t){
    if(vis1[i][j]) return 0;
    vis1[i][j] = true;

    int cnt = 0;
    for(int k = 0; k < 4; ++k){
        int ni = i + dir_i[k];
        int nj = j + dir_j[k];
        if(ni < 0 || nj < 0 || ni >= n || nj >= n || vis1[ni][nj] || mat[ni][nj].t != t) continue;
        cnt += dfs1(ni, nj, t);
    }
    return 1 + cnt;
}

int dfs2(int i, int j, int c){
    if(vis2[i][j]) return 0;
    vis2[i][j] = true;

    int cnt = 0;
    for(int k = 0; k < 4; ++k){
        int ni = i + dir_i[k];
        int nj = j + dir_j[k];
        if(ni < 0 || nj < 0 || ni >= n || nj >= n || vis2[ni][nj] || mat[ni][nj].c != c) continue;
        cnt += dfs2(ni, nj, c);
    }
    return 1 + cnt;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            char t; cin >> t;
            int c; cin >> c;
            mat[i][j] = {t - 'A', c};
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(!vis1[i][j]) maxT[mat[i][j].t] = max(maxT[mat[i][j].t], dfs1(i, j, mat[i][j].t));
            if(!vis2[i][j]) maxC[mat[i][j].c] = max(maxC[mat[i][j].c], dfs2(i, j, mat[i][j].c));
        }
    }

    int a = 0, b = 0;

    for(int i = 0; i < 28; ++i){
        if(maxT[i]) a += maxT[i] * (maxT[i] - 1) / 2;
        if(maxC[i]) b += maxC[i] * (maxC[i] - 1) / 2;
    }
    cout << a << ' ' << b << '\n';
}
