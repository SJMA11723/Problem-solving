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
        int lim = min(n, m) / 2;
        char mat[n][m];
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j) cin >> mat[i][j];

        int ans = 0;
        for(int k = 0; k < lim; ++k){
            string s;

            /// up
            for(int j = k; j < m - k; ++j) s += mat[k][j];

            /// right
            for(int i = k + 1; i < n - k; ++i) s += mat[i][m - k - 1];

            /// down
            for(int j = m - k - 2; k <= j; --j) s += mat[n - k - 1][j];

            /// left
            for(int i = n - k - 2; k < i; --i) s += mat[i][k];

            s = s + s.substr(0, 3);

            /// 1543
            for(int i = 3; i < s.size(); ++i)
                if(s[i] == '3' && s[i - 1] == '4' && s[i - 2] == '5' && s[i - 3] == '1') ans++;
        }
        cout << ans << '\n';
    }
}
