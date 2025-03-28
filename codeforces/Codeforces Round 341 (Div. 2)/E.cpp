/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

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
    int n, k, x;
    int64_t b;
    cin >> n >> b >> k >> x;

    matrix A(x, x);

    int cnt[10] = {};
    for(int i = 0; i < n; ++i){
        int d; cin >> d;
        cnt[d]++;
    }

    for(int i = 0; i < x; ++i){
        for(int d = 1; d <= 9; ++d){
            int r = (i * 10 + d) % x;
            A[i][r] += cnt[d];
        }
    }

    A = bin_exp(A, b);

    cout << A[0][k] << '\n';
}
