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
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        long long mat[n][m];
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j) cin >> mat[i][j];
        map<int, long long> diag, diagInv;
        long long ans = 0;
        for(int i = 0; i < n; ++i){
            for(int c = 0; i + c < n && c < m; ++c) diag[i] += mat[i + c][c];

            for(int c = 0; c <= i && c < m; ++c) diagInv[i] += mat[i - c][c];
        }

        for(int c = 1; c < m; ++c){
            for(int i = 0; i < n && c + i < m; ++i) diag[-c] += mat[i][c + i];

            for(int i = n - 1; 0 <= i && c + n - 1 - i < m; --i) diagInv[c + n - 1] += mat[i][c + n - 1 - i];

            //cout << diag[n + c] << ' ' << diagInv[n + c - 1] << '\n';
        }

        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j){
                ans = max({ans, diag[i - j] + diagInv[i + j] - mat[i][j]});
            }

        cout << ans << '\n';
    }
}
