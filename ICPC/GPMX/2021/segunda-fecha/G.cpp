/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int dir_i[8] = {1, 1, 1, 0, -1, -1, -1, 0}, dir_j[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    char mat[n][m];
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> mat[i][j];
        }
    }

    int ans = 0;
    int dp[n][m];
    memset(dp, 0, sizeof(dp));

    for(char c = 'Z'; 'A' <= c; --c){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(mat[i][j] != c) continue;

                int maxCnt = 0;
                for(int k = 0; k < 8; ++k){
                    int ni = i + dir_i[k];
                    int nj = j + dir_j[k];
                    //if(!(ni < 0 || nj < 0 || ni >= n || nj >= m)) cout << mat[ni][nj] << '\n';
                    if(ni < 0 || nj < 0 || ni >= n || nj >= m || mat[i][j] + 1 != mat[ni][nj]) continue;
                    maxCnt = max(maxCnt, dp[ni][nj]);
                }
                dp[i][j] = maxCnt + 1;
                ans = max(ans, maxCnt + 1);
            }
        }

        /*cout << c << '\n';
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                cout << dp[i][j] << ' ';
            }
            cout << '\n';
        } cout << '\n';
        */
    }

    cout << ans << '\n';
}

