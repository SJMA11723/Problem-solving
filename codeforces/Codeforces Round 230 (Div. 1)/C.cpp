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

    matrix(){}

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

int bin_exp(int a, int64_t b){
    if(!b) return 1;
    int tmp = bin_exp(a, b / 2);
    if(b % 2) return 1ll * tmp * tmp % MOD * a % MOD;
    return 1ll * tmp * tmp % MOD;
}

int fact[41], inv_fact[41];

int combi(int n, int k){
    if(k > n || n < 0) return 0;
    return 1ll * fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int64_t n; cin >> n;
    int k; cin >> k;
    int len = 2 * (k + 1) + 1;
    matrix A(len, len);

    fact[0] = 1;
    for(int i = 1; i <= k; ++i) fact[i] = 1ll * i * fact[i - 1] % MOD;
    inv_fact[k] = bin_exp(fact[k], MOD - 2);
    for(int i = k; 0 < i; --i) inv_fact[i - 1] = 1ll * i * inv_fact[i] % MOD;

    for(int i = 0; i <= k; ++i) A[i][k + 1 + i] = 1;
    for(int i = k + 1; i + 1 < len; ++i){
        int _k = i - k - 1;
        for(int j = 0; j <= _k; ++j){
            A[i][j] = 1ll * combi(_k, j) * bin_exp(2, _k - j) % MOD;
        }
        for(int j = 0; j <= _k; ++j){
            A[i][j + k + 1] = combi(_k, j);
        }
    }
    A[len - 1][len - 1] = 1;
    A[len - 1][len - 2] = 1;

    A = bin_exp(A, n);

    int arr[len] = {};
    for(int i = k + 1; i + 1 < len; ++i) arr[i] = 1;
    arr[0] = 1; /// A_0(0) = f_0*0^0 = 1 * 1

    int ans = 0;
    for(int i = 0; i < len; ++i){
        ans += 1ll * arr[i] * A[len - 1][i] % MOD;
        if(ans >= MOD) ans -= MOD;
    }
    cout << ans << '\n';
}
