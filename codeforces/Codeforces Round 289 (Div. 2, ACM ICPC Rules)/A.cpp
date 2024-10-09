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
    int n; cin >> n;
    int ans = 1;
    int mat[n][n];
    for(int i = 0; i < n; ++i) mat[0][i] = mat[i][0] = 1;

    for(int i = 1; i < n; ++i)
    for(int j = 1; j < n; ++j){
        mat[i][j] = mat[i - 1][j] + mat[i][j - 1];
        ans = max(ans, mat[i][j]);
    }
    cout << ans << '\n';
}
