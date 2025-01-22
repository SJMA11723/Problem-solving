/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

bool is_prime(int x){
    if(x == 1) return false;
    for(int i = 2; i * i <= x; ++i){
        if(x % i == 0) return false;
    }
    return true;
}

struct matrix{
    vector<vector<int>> mat;
    int n, m;
    matrix(int _n, int _m, bool I = false){
        n = _n;
        m = _m;
        mat.resize(n, vector<int>(m));
        if(I){
            for(int i = 0; i < n; ++i){
                mat[i][i] = 1;
            }
        }
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
    matrix A(18, 18);
    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < 9; ++j){
            if(is_prime(i + j + 2)) A[i][j] = 1;
        }
        A[i][i + 9] = 1;
        A[i + 9][i + 9] = 1;
    }
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        matrix B = bin_exp(A, n);
        int ans = 0;
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                ans += B[i][j + 9];
                if(ans >= MOD) ans -= MOD;
            }
        }
        ans -= 5;
        if(ans < 0) ans += MOD;
        cout << ans << '\n';
    }
}
