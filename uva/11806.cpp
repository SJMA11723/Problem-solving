/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define is_on(n, i) ((n) & (1 << (i)))
#define MAXC 500

using namespace std;

const int MOD = 1000007;
int coef[MAXC + 1][MAXC + 1];

int binom(int n, int k){
    if(n < 0 || k < 0 || n < k) return 0;
    return coef[n][k];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    coef[0][0] = 1;
    for(int i = 1; i <= MAXC; ++i)
    for(int j = 0; j <= i; ++j){
        coef[i][j] = binom(i - 1, j) + binom(i - 1, j - 1);
        if(coef[i][j] >= MOD) coef[i][j] -= MOD;
    }

    int t; cin >> t;
    for(int tt = 1; tt <= t; ++tt){
        int m, n, k; cin >> m >> n >> k;

        int c = n * m;
        int ans = binom(c, k);

        ///  cuento el complemento y lo resto
        int lim = 1 << 4;
        /// 0123 -> LURD
        for(int mask = 1; mask < lim; ++mask){
            int col = 0, row = 0;

            int cnt_empty = 0;
            for(int i = 0; i < 4; ++i){
                if(!is_on(mask, i)) continue;
                if(i % 2){
                    cnt_empty += n - col;
                    row++;
                } else {
                    cnt_empty += m - row;
                    col++;
                }
            }

            if(__builtin_parity(mask)){
                ans -= binom(n * m - cnt_empty, k);
                if(ans < 0) ans += MOD;
            } else {
                ans += binom(n * m - cnt_empty, k);
                if(ans >= MOD) ans -= MOD;
            }
        }

        cout << "Case " << tt << ": " << ans << '\n';
    }
}
