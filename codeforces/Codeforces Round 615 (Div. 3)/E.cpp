/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    int mat[n][m];
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> mat[i][j];
        }
    }

    int ans = 0;
    for(int j = 0; j < m; ++j){
        map<int, int> pos;
        for(int i = 0; i < n; ++i) pos[i * m + j + 1] = i;

        int cnt[n] = {};
        for(int i = 0; i < n; ++i)
            if(pos.count(mat[i][j])) cnt[(i - pos[mat[i][j]] + n) % n]++;

        int column_moves = INT_MAX;
        for(int i = 0; i < n; ++i) column_moves = min(column_moves, i + n - cnt[i]);
        ans += column_moves;
    }

    cout << ans << '\n';
}
