/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int di[4] = {0, 0, 1, -1};
int dj[4] = {-1, 1, 0, 0};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        int mat[n][m];
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j) cin >> mat[i][j];

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                int maxi = 0;
                for(int k = 0; k < 4; ++k){
                    int ni = i + di[k];
                    int nj = j + dj[k];
                    if(ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
                    maxi = max(maxi, mat[ni][nj]);
                }
                if(maxi < mat[i][j]) mat[i][j] = maxi;
                cout << mat[i][j] << ' ';
            }
            cout << '\n';
        }
    }
}
