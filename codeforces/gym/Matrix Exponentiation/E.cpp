/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct matrix{
    vector<vector<uint32_t>> mat;
    int n, m;
    matrix(int _n, int _m, bool I = false){
        n = _n;
        m = _m;
        mat.resize(n, vector<uint32_t>(m));
        if(I) for(int i = 0; i < n; ++i) mat[i][i] = 1;
    }

    vector<uint32_t>& operator[](int i){
        return mat[i];
    }

    matrix operator*(matrix &B){
        matrix res(n, B.m);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < B.m; ++j){
                for(int k = 0; k < m; ++k){
                    res[i][j] += mat[i][k] * B[k][j];
                }
            }
        }
        return res;
    }
};

matrix bin_exp(matrix &A,  int64_t n){
    if(!n) return matrix(A.n, A.n, true);
    matrix tmp = bin_exp(A, n / 2);
    if(n % 2) return tmp * tmp * A;
    return tmp * tmp;
}

int di[8] = {-2, -2, -1, 1, 2, 2, -1, 1};
int dj[8] = {-1, 1, 2, 2, -1, 1, -2, -2};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k; cin >> k;
    int n = 8 * 8;
    matrix A(2 * n, 2 * n);
    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            int u = i * 8 + j;
            for(int k = 0; k < 8; ++k){
                int ni = i + di[k];
                int nj = j + dj[k];
                if(ni < 0 || nj < 0 || ni >= 8 || nj >= 8) continue;
                int v = ni * 8 + nj;
                A[u][v] = 1;
            }
            A[u][u + n] = 1;
            A[u + n][u + n] = 1;
        }
    }
    A = bin_exp(A, k + 1);
    uint32_t ans = 0;
    for(int i = 0; i < 64; ++i) ans += A[0][i + n];
    cout << ans << '\n';
}
