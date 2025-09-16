#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    char mat[n][m];
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j) cin >> mat[i][j];

    int T(0), A(0), P(0);
    for(int j = m - 1; 0 <= j; --j){
        init:
        bool started = false;
        int cnt = 0;
        int f = n;
        for(int i = 0; i < n; ++i){
            if(mat[i][j] == '.'){
                if(!started) continue;
                f = i;
                break;
            } else {
                started = true;
                cnt++;
            }
        }

        if(!cnt){
            //cout << j << endl;
            continue;
        }

        f -= cnt;
        if(cnt == 1){
            mat[f][j] = '.';
            for(int k = 0; k < 5; ++k) mat[f + k][j - 1] = '.';
            mat[f][j - 2] = '.';
            T++;
        } else if(cnt == 3){
            mat[f][j] = mat[f + 1][j] = mat[f + 2][j] = '.';
            mat[f][j - 1] = mat[f + 2][j - 1] = '.';
            for(int k = 0; k < 5; ++k) mat[f + k][j - 2] = '.';
            P++;
        } else {
            for(int k = 0; k < 5; ++k) mat[f + k][j] = '.';
            mat[f][j - 1] = mat[f + 2][j - 1] = '.';
            for(int k = 0; k < 5; ++k) mat[f + k][j - 2] = '.';
            A++;
        }

        //cout << '\n';
        //for(int i = 0; i < n; ++i, cout << '\n')
        //for(int jj = 0; jj < m; ++jj) cout << mat[i][jj];

        goto init;
    }

    cout << T << ' ' << A << ' ' << P << '\n';
}