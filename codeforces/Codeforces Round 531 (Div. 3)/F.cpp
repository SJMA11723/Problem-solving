/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define is_on(n, i) ((n) & (1ll << (i)))

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    int mat[n][m], add[n][n], add2[n][n];

    for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j) add[i][j] = add2[i][j] = INT_MAX;

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> mat[i][j];

    for(int i = 0; i < n; ++i){
        for(int k = 0; k < n; ++k){
            for(int j = 0; j < m; ++j){
                add[i][k] = min(add[i][k], abs(mat[i][j] - mat[k][j]));
                if(j) add2[i][k] = min(add2[i][k], abs(mat[i][j - 1] - mat[k][j]));
            }
        }
    }

    if(n == 1){
        cout << add2[0][0] << '\n';
        return 0;
    }

    int dp[1 << n][n];
    int ans = 0;
    int lim = 1 << n;
    for(int i = 0; i < n; ++i){ /// fijo la primera
        memset(dp, 0, sizeof(dp));
        dp[1 << i][i] = INT_MAX;

        for(int mask = 1; mask < lim; ++mask){
            if(!is_on(mask, i)) continue;

            for(int j = 0; j < n; ++j){ /// fijo j como la ultima
                if(!is_on(mask, j)) continue;

                for(int k = 0; k < n; ++k){ /// fijo k como la penultima
                    if(!is_on(mask, k)) continue;

                    int min_prev = min(dp[mask ^ (1 << j)][k], add[j][k]);
                    if(__builtin_popcount(mask) == n) min_prev = min(min_prev, add2[j][i]);
                    dp[mask][j] = max(dp[mask][j], min_prev);
                }
            }
        }
        ans = max(ans, *max_element(dp[(1 << n) - 1], dp[(1 << n) - 1] + n));
    }

    cout << ans << '\n';
}
