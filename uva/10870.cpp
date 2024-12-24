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
                for(int k = 0; k < m; ++k){
                    res[i][j] += 1ll * mat[i][k] * b[k][j] % MOD;
                    if(res[i][j] >= MOD) res[i][j] -= MOD;
                }
            }
        }

        return res;
    }
};

matrix bin_exp(matrix A, int64_t n){
    if(!n) return matrix(A.n, A.n, true);
    matrix tmp = bin_exp(A, n / 2);
    if(n % 2) return tmp * tmp * A;
    return tmp * tmp;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, d; cin >> d >> n >> m;
    while(n || m || d){
        MOD = m;
        int C[d];
        for(int i = 0; i < d; ++i){
            cin >> C[i];
            C[i] %= MOD;
        }

        int f[d];
        for(int i = 0; i < d; ++i){
            cin >> f[i];
            f[i] %= MOD;
        }

        n--;
        if(n < d) cout << f[n] << '\n';
        else {
            matrix F(d, d);

            for(int i = 1; i < d; ++i) F[i - 1][i] = 1;
            for(int i = 0; i < d; ++i) F[d - 1][i] = C[d - 1 - i];

            F = bin_exp(F, n);

            int ans = 0;
            for(int i = 0; i < d; ++i){
                ans += f[i] * F[0][i] % MOD;
                if(ans >= MOD) ans -= MOD;
            }

            cout << ans << '\n';
        }

        cin >> d >> n >> m;
    }
}
