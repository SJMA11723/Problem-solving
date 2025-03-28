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

    vector<int>& operator[](int i){
        return mat[i];
    }

    matrix operator*(matrix &B){
        matrix res(n, B.m);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < B.m; ++j){
                for(int k = 0; k < m; ++k){
                    res[i][j] += 1ll * mat[i][k] * B[k][j] % MOD;
                    if(res[i][j] >= MOD) res[i][j] -= MOD;
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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int m, n; cin >> m >> n;
        matrix A(5, 5);
        A[0][1] = 1;
        A[1][2] = 1;
        A[2][3] = 1;
        A[3] = {1, 1, 1, 1, 0};
        A[4] = {1, 1, 1, 1, 1};

        int arr[5] = {0, 0, 0, 1, 1};
        matrix B = bin_exp(A, max(0, n - 3));
        A = bin_exp(A, max(0, m - 1 - 3));
        int ans = 0;
        if(n >= 3) ans = (B[4][3] + B[4][4]) % MOD;
        if(m - 1 >= 3) ans = (ans - ((A[4][3] + A[4][4]) % MOD) + MOD) % MOD;
        cout << ans << '\n';
    }
}
