/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 7;

struct matrix{
    int n;
    int64_t mat[201][201];
    matrix(int _n, bool I){
        n = _n;
        memset(mat, 0, sizeof(mat));
        if(!I) return;

        for(int i = 0; i < n; ++i){
            mat[i][i] = 1;
        }
    }
    matrix operator*(matrix &b){
        matrix res(n, false);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                for(int k = 0; k < n; ++k){
                    res.mat[i][j] += mat[i][k] * b.mat[k][j] % MOD;
                    res.mat[i][j] %= MOD;
                }
            }
        }
        return res;
    }
};

matrix bin_exp(matrix a, int b){
    if(!b) return matrix(a.n, true);

    matrix tmp = bin_exp(a, b / 2);

    if(b % 2) return tmp * tmp * a;
    return tmp * tmp;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, d, k, s;
    cin >> n >> d >> k >> s;
    s--;
    matrix A(n + 1, false);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j <= d; ++j){
            A.mat[i][(i + j) % n] = A.mat[(i + j) % n][i] = 1;
            A.mat[i][(i - j + n) % n] = A.mat[(i - j + n) % n][i] = 1;
        }
        A.mat[i][n] = 1;
    }
    A.mat[n][n] = 1;

    A = bin_exp(A, k);

    cout << A.mat[s][n] << '\n';
}
