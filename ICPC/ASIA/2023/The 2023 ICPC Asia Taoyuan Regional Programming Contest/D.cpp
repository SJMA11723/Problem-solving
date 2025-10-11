#include <bits/stdc++.h>

using namespace std;

            /// DURL
int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, 1, -1};

int di2[4] = {0, 0, 1, -1};
int dj2[4] = {-1, 1, 0, 0};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    for(int tt = 1; tt <= t; ++tt){
        int n, m, d1, d2;
        cin >> n >> m >> d1 >> d2;
        char mat[n][m];
        for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j){
            cin >> mat[i][j];
            if(mat[i][j] == '.') mat[i][j] = 0;
        }

        for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j){
            if(mat[i][j] != 'V') continue;

            for(int k = 0; k < 4; ++k){
                int ni = i + di[k];
                int nj = j + dj[k];

                if(ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
                if(mat[ni][nj] == 'V') continue;

                mat[ni][nj] = max(mat[ni][nj], (char)d1);

                ni += di2[k];
                nj += dj2[k];

                if(ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
                if(mat[ni][nj] == 'V') continue;

                mat[ni][nj] = max(mat[ni][nj], (char)d2);
            }
        }

        cout << "Airplane #" << tt << ":\n";
        for(int i = 0; i < n; ++i, cout << '\n')
        for(int j = 0; j < m; ++j){
            if(mat[i][j] == 'V') cout << 'V';
            else cout << (short)mat[i][j];
        }
    }
}
