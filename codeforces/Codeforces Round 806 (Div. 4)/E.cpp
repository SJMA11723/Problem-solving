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
        int n; cin >> n;
        vector< vector<char> > mat(n, vector<char>(n));
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                cin >> mat[i][j];
        int ans = 0;
        for(int i = 0; i < n / 2; ++i){
            int lim = n - i - 1;
            for(int j = i; j < lim; ++j){
                int cnt = mat[i][j] + mat[j][n - i - 1] + mat[n - i - 1][n - j - 1] + mat[n - j - 1][i] - '0' * 4;
                ans += min(cnt, 4 - cnt);
            }
        }
        cout << ans << '\n';
    }
}
