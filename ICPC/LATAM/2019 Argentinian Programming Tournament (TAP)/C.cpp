#include <bits/stdc++.h>

using namespace std;

const int INF = 1e5;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    int L[n + 2][m + 2], R[n + 2][m + 2], U[n + 2][m + 2], D[n + 2][m + 2];
    memset(L, 0, sizeof(L));
    memset(R, 0, sizeof(R));
    memset(U, 0, sizeof(U));
    memset(D, 0, sizeof(D));

    char mat[n + 2][m + 2];
    memset(mat, 0, sizeof(mat));
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> mat[i][j];
        }
    }

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j)
            if(mat[i][j] == '*'){
                L[i][j] = 1 + L[i][j - 1];
                if(mat[i + 1][j] == '*' || mat[i - 1][j] == '*') L[i][j] = INF;
            }
        for(int j = m; 0 < j; --j)
            if(mat[i][j] == '*'){
                R[i][j] = 1 + R[i][j + 1];
                if(mat[i + 1][j] == '*' || mat[i - 1][j] == '*') R[i][j] = INF;
            }
    }

    for(int j = 1; j <= m; ++j){
        for(int i = 1; i <= n; ++i)
            if(mat[i][j] == '*'){
                U[i][j] = 1 + U[i - 1][j];
                if(mat[i][j - 1] == '*' || mat[i][j + 1] == '*') U[i][j] = INF;
            }
        for(int i = n; 0 < i; --i)
            if(mat[i][j] == '*'){
                D[i][j] = 1 + D[i + 1][j];
                if(mat[i][j - 1] == '*' || mat[i][j + 1] == '*') D[i][j] = INF;
            }
    }

    int ans = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(mat[i][j] == '*' && U[i - 1][j] && U[i - 1][j] < INF && D[i + 1][j] < INF &&
               U[i - 1][j] == L[i][j - 1] && L[i][j - 1] == R[i][j + 1] && D[i + 1][j] > U[i - 1][j]) ans++;
        }
    }
    cout << ans << '\n';
}
