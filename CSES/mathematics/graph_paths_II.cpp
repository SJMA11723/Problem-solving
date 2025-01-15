/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

struct matrix{
    vector<vector<int64_t>> mat;
    int n, m;
    matrix(int _n, int _m, bool I = false){
        n = _n;
        m = _m;
        mat.resize(n, vector<int64_t>(m, LLONG_MAX));
        if(I) for(int i = 0; i < n; ++i) mat[i][i] = 0;
    }

    vector<int64_t>& operator[](int i){
        return mat[i];
    }

    matrix operator*(matrix &B){
        matrix res(n, B.m);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < B.m; ++j){
                res[i][j] = LLONG_MAX;
                for(int k = 0; k < m; ++k){
                    if(mat[i][k] == LLONG_MAX) continue;
                    if(B[k][j] == LLONG_MAX) continue;
                    res[i][j] = min(res[i][j], mat[i][k] + B[k][j]);
                }
            }
        }
        return res;
    }
};

matrix bin_exp(matrix &A,  int64_t n){
    if(!n) return matrix(A.n, A.n, 1);
    matrix tmp = bin_exp(A, n / 2);
    if(n % 2) return tmp * tmp * A;
    return tmp * tmp;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k; cin >> n >> m >> k;
    matrix A(n, n);
    for(int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;
        int64_t c; cin >> c;
        a--, b--;
        A[a][b] = min(A[a][b], c);
    }
    if(!k){
        cout << (n == 1 ? 0 : -1) << '\n';
        return 0;
    }
    A = bin_exp(A, k);
    cout << (A[0][n - 1] == LLONG_MAX ? -1 : A[0][n - 1]) << '\n';
}
