#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

struct matrix{
    vector<vector<int>> mat;
    int n;
    matrix(int _n, bool I = false){
        n = _n;
        mat.resize(n, vector<int>(n, 0));

        if(I) for(int i = 0; i < n; ++i) mat[i][i] = 1;
    }

    vector<int> & operator[](int i){
        return mat[i];
    }

    matrix operator*(const matrix &B){
        matrix res(n);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                for(int k = 0; k < n; ++k){
                    res[i][j] += 1ll * mat[i][k] * B.mat[k][j] % MOD;
                    if(res[i][j] >= MOD) res[i][j] -= MOD;
                }
            }
        }
        return res;
    }
};

matrix bin_exp(const matrix A, int n){
    if(!n) return matrix(A.n, true);

    matrix tmp = bin_exp(A, n / 2);

    if(n % 2) return tmp * tmp * A;
    return tmp * tmp;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;

    matrix A(m);
    for(int i = 1; i <= m; ++i)
        for(int j = 1; j <= m; ++j){
            A[i - 1][j - 1] = __gcd(i, j) == 1;
        }

    A = bin_exp(A, n);
    int ans = 0;
    for(int i = 0; i < m; ++i){
        ans += A[0][i];
        if(ans >= MOD) ans -= MOD;
    }
    cout << ans << '\n';
}

