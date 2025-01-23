/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define is_on(n, i) ((n) & (1ll << (i)))

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
            for(int i = 0; i < n; ++i){
                mat[i][i] = 1;
            }
        }
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

matrix powA[31];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, q; cin >> n >> m >> q;
    matrix A(n, n);
    for(int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;
        a--, b--;
        A[a][b]++;
    }

    powA[0] = A;
    for(int i = 1; i < 31; ++i) powA[i] = powA[i - 1] * powA[i - 1];

    while(q--){
        int s, t, k; cin >> s >> t >> k;
        s--, t--;
        int srow[n] = {}; srow[s] = 1;
        for(int i = 0; i < 31; ++i){
            int new_srow[n] = {};
            if(is_on(k, i)){
                for(int j = 0; j < n; ++j){
                    for(int l = 0; l < n; ++l){
                        new_srow[j] += 1ll * srow[l] * powA[i][l][j] % MOD;
                        if(new_srow[j] >= MOD) new_srow[j] -= MOD;
                    }
                }
                memcpy(srow, new_srow, sizeof(srow));
            }
        }
        cout << srow[t] << '\n';
    }
}
