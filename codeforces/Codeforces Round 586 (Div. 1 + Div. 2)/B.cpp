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
    int64_t mat[n][n];
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j) cin >> mat[i][j];

    cout << (int64_t)sqrt(mat[0][1] * mat[0][2] / mat[1][2]) << ' ' << (int64_t)sqrt(mat[1][0] * mat[1][2] / mat[0][2]) << ' ';
    for(int i = 2; i < n; ++i) cout << (int64_t)sqrt(mat[i][0] * mat[i][1] / mat[0][1]) << ' ';
    cout << '\n';
}
