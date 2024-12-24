/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int MOD2 = 1e9 + 6;

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
                    res[i][j] += (1ll * mat[i][k] * b[k][j] % MOD2 + MOD2) % MOD2;
                    if(res[i][j] >= MOD2) res[i][j] -= MOD2;
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

int bin_exp2(int a, int64_t b){
    if(!b) return 1;
    int tmp = bin_exp2(a, b / 2);
    if(b % 2) return 1ll * tmp * tmp % MOD * a % MOD;
    return 1ll * tmp * tmp % MOD;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int64_t n; cin >> n;
    int f1, f2, f3, c;
    cin >> f1 >> f2 >> f3 >> c;

    matrix A(5, 5);
    A[0][0] = 1;
    A[1][0] = 2, A[1][1] = 1;
    A[2][3] = 1;
    A[3][4] = 1;
    A[4][0] = -6;
    for(int i = 1; i < 5; ++i) A[4][i] = 1;

    A = bin_exp(A, n - 1);

    int ans = bin_exp2(c, 1ll * A[2][0] + 8ll * A[2][1]);
    ans = 1ll * ans * bin_exp2(f1, A[2][2]) % MOD;
    ans = 1ll * ans * bin_exp2(f2, A[2][3]) % MOD;
    ans = 1ll * ans * bin_exp2(f3, A[2][4]) % MOD;
    cout << ans << '\n';
}
