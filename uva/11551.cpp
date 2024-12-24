/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000;

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
                int64_t r = 0;
                for(int k = 0; k < m; ++k){
                    r += 1ll * mat[i][k] * b[k][j] % MOD;
                    if(r >= MOD) r -= MOD;
                }
                res[i][j] = r;
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

    int t; cin >> t;
    while(t--){
        int n, r; cin >> n >> r;
        int f[n];
        for(int i = 0; i < n; ++i){
            int64_t x; cin >> x;
            f[i] = x % MOD;
        }

        matrix A(n, n);
        for(int i = 0; i < n; ++i){
            int k; cin >> k;
            while(k--){
                int idx; cin >> idx;
                A[i][idx] = 1;
            }
        }

        A = bin_exp(A, r);
        for(int i = 0; i < n; ++i){
            int res = 0;
            for(int j = 0; j < n; ++j){
                res += A[i][j] * f[j] % MOD;
                if(res >= MOD) res -= MOD;
            }
            cout << res;
            if(i + 1 < n) cout << ' ';
            else cout << '\n';
        }
    }
}
