#/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()

const ll MOD = 1e9 + 7;

struct matrix{
    vector<vi> mat;
    int n;

    matrix(int _n, bool I = false){
        n = _n;
        mat.resize(n, vi(n));
        if(I) for(int i = 0; i < n; ++i) mat[i][i] = 1;
    }

    vi & operator[](int i){
        return mat[i];
    }

    matrix operator*(matrix &b){
        matrix res(n);
        for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
        for(int k = 0; k < n; ++k){
            res[i][j] += 1ll * mat[i][k] * b[k][j] % MOD;
            if(res[i][j] >= MOD) res[i][j] -= MOD;
        }
        return res;
    }
};

matrix bin_exp(matrix &A, int n){
    if(!n) return matrix(A.n, 1);
    matrix tmp = bin_exp(A, n / 2);
    if(n & 1) return tmp * tmp * A;
    return tmp * tmp;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, l, r;
    cin >> n >> l >> r;
    matrix A(3);
    int cnt_mod[3] = {};
    while(l % 3 && l <= r) cnt_mod[l++ % 3]++;
    while(r % 3 != 2 && l <= r) cnt_mod[r-- % 3]++;
    if(l <= r){
        int K = r / 3 - (l - 1) / 3;
        cnt_mod[0] += K;
        cnt_mod[1] += K;
        cnt_mod[2] += K;
    }

    A[0] = {cnt_mod[0], cnt_mod[1], cnt_mod[2]};
    A[1] = {cnt_mod[2], cnt_mod[0], cnt_mod[1]};
    A[2] = {cnt_mod[1], cnt_mod[2], cnt_mod[0]};

    matrix ans = bin_exp(A, n);
    cout << ans[0][0] << '\n';
}
