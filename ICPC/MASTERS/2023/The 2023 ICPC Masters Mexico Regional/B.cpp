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

        if(I){
            for(int i = 0; i < n; ++i) mat[i][i] = 1;
        }
    }

    vector<int> &operator[](int i){
        return mat[i];
    }

    matrix operator*(matrix b){
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

    int64_t k; cin >> k;

    if(k < 3){
        cout << k + 1 << '\n';
        return 0;
    }

    int f[4] = {3, 1, 2, 3};
    int C[4] = {1, 1, 2, 3};
    matrix A(4, 4);
    A[0][0] = A[1][2] = A[2][3] = 1;
    for(int i = 0; i < 4; ++i) A[3][i] = C[i];

    A = bin_exp(A, k);

    int ans = 0;
    for(int i = 0; i < 4; ++i){
        ans += 1ll * A[1][i] * f[i] % MOD;
        if(ans >= MOD) ans -= MOD;
    }

    cout << ans << '\n';
}
