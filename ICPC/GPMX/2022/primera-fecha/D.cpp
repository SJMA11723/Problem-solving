/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 7;

struct matrix{
    int n;
    vector<vector<int>> mat;

    matrix(int n, bool I = true){
        this->n = n;
        mat = vector<vector<int>>(n, vector<int>(n));

        if(I)
        for(int i = 0; i < n; ++i)
        mat[i][i] = 1;
    }

    matrix(vector<vector<int>> &M){
        n = M.size();
        mat = M;
    }

    matrix operator*(matrix &b){
        vector<vector<int>> res(n, vector<int>(n));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                for(int k = 0; k < n; ++k){
                    res[i][j] += (int64_t)mat[i][k] * b.mat[k][j] % MOD;
                    res[i][j] %= MOD;
                }
            }
        }
        return res;
    }
};

matrix bin_exp(matrix &A, int n){
    if(!n) return matrix(A.n);

    matrix tmp = bin_exp(A, n / 2);

    if(n % 2) return tmp * tmp * A;
    return tmp * tmp;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;

    matrix adj(n, false);

    for(int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;
        a--; b--;
        adj.mat[a][b] = 1;
        adj.mat[b][a] = 1;
    }

    matrix ways = bin_exp(adj, k);

    int64_t ans = 0;
    for(int i = 0; i < n; ++i) ans += ways.mat[0][i];
    ans %= MOD;

    cout << ans << '\n';
}
