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
        matrix res(n,  B.m);
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
    int n; cin >> n;
    if(n == 1){
        cout << "2\n";
        return 0;
    }
    if(n == 2){
        cout << "24\n";
        return 0;
    }
    matrix A(4, 4);
    A[0][0] = 2;
    A[1][1] = 2; A[1][2] = 4;
    A[2][3] = 1;
    A[3][0] = 2; A[3][2] = 4; A[3][3] = 2;
    A = bin_exp(A, n - 2);

    int arr[4] = {4, 0, 2, 12}, ans = 0;
    for(int i = 0; i < 4; ++i){
        ans += 1ll * arr[i] * A[3][i] % MOD;
        if(ans >= MOD) ans -= MOD;
        ans += 1ll * arr[i] * A[1][i] % MOD;
        if(ans >= MOD) ans -= MOD;
    }
    ans += ans;
    if(ans >= MOD) ans -= MOD;
    cout << ans << '\n';
}
