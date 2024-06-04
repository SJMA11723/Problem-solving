#include<bits/stdc++.h>

using namespace std;

struct matrix{
    int n;
    vector<vector<long double>> mat;

    matrix(int _n, bool I = false){
        n = _n;
        mat.resize(n, vector<long double>(n));

        if(I)
        for(int i = 0; i < n; ++i) mat[i][i] = 1;
    }

    matrix operator*(matrix b){
        matrix res(n);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                for(int k = 0; k < n; ++k){
                    res.mat[i][j] += mat[i][k] * b.mat[k][j];
                }
            }
        }

        return res;
    }
};

matrix bin_exp(matrix A, int n){
    if(!n) return matrix(A.n, true);

    matrix tmp = bin_exp(A, n / 2);

    if(n % 2) return tmp * tmp * A;
    return tmp * tmp;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M; cin >> N >> M;

    matrix adj(N);
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            cin >> adj.mat[i][j];
        }
    }

    matrix res = bin_exp(adj, M);

    for(int i = 0; i < N; ++i)
        cout << fixed << setprecision(5) << res.mat[0][i] << '\n';

    return 0;
}
