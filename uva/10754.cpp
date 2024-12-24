/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int MOD = 1e9 + 7;

struct matrix{
    vector<vector<int>> mat;
    int n, m;

    matrix(int _n, int _m, bool I = false){
        n = _n;
        m = _m;
        mat.resize(n, vector<int>(m));

        if(I) for(int i = 0; i < n; ++i) mat[i][i] = 1;
    }

    vector<int> &operator[](int i){
        return mat[i];
    }

    matrix operator*(matrix &b){
        matrix res(n, b.m);

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < b.m; ++j){
                int64_t r = 0;
                for(int k = 0; k < m; ++k){
                    r += 1ll * mat[i][k] * b[k][j] % MOD;
                    if(r >= MOD) r -= MOD;
                }
                res[i][j] = r;
            }
        }

        return res;
    }
};

matrix bin_exp(matrix &A, int64_t n){
    if(!n) return matrix(A.n, A.n, true);
    matrix tmp = bin_exp(A, n / 2);
    if(n % 2) return tmp * tmp * A;
    return tmp * tmp;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while(t--){
        int k, m, n;
        cin >> k >> m >> n;
        MOD = m;
        int C[k + 1];
        for(int i = 0; i <= k; ++i){
            cin >> C[i];
            C[i] %= MOD;
            if(C[i] < 0) C[i] = (1ll * C[i] + MOD) % MOD;
        }

        int f[k];
        for(int i = 0; i < k; ++i){
            cin >> f[i];
            f[i] %= MOD;
            if(f[i] < 0) f[i] = (1ll * f[i] + MOD) % MOD;
        }

        if(n < k) cout << f[n] << '\n';
        else {
            matrix F(k + 1, k + 1);

            F[0][0] = 1;
            for(int i = 1; i < k; ++i) F[i][i + 1] = 1;
            for(int i = 1; i <= k; ++i) F[k][i] = C[k - i];
            F[k][0] = 1;

            F = bin_exp(F, n);

            int64_t ans = k ? 1ll * C[k] * F[1][0] % MOD : C[k];
            for(int i = 0; i < k; ++i){
                ans += 1ll * f[i] * F[1][i + 1] % MOD;
                if(ans >= MOD) ans -= MOD;
            }

            cout << ans << '\n';
        }
        if(t) cout << '\n';
    }
}
