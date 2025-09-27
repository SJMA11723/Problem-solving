/**
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

const ll MOD = 1e6;

struct matrix{
    int n;
    vector<vi> mat;

    matrix(int _n, bool I = false){
        n = _n;
        mat.resize(n, vi(n));
        if(I) for(int i = 0; i < n; ++i) mat[i][i] = 1;
    }

    vi & operator[](int i){
        return mat[i];
    }

    matrix operator*(matrix &B){
        matrix res(n, n);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                res[i][j] = 0;
                for(int k = 0; k < n; ++k){
                    res[i][j] += 1ll * mat[i][k] * B[k][j] % MOD;
                }
            }
        }
        return res;
    }
};

matrix bin_exp(matrix &A, ll n){
    if(!n) return matrix(A.n, 1);
    matrix tmp = bin_exp(A, n / 2);
    if(n & 1) return tmp * tmp * A;
    return tmp * tmp;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, k, l; cin >> n >> k >> l;
    n /= 5;
    k %= MOD;
    l %= MOD;

    matrix A(2);
    A[0][1] = 1;
    A[1][0] = l;
    A[1][1] = k;

    A = bin_exp(A, n);

    int ans = (1ll * A[0][1] * k + A[0][0] * 1ll) % MOD;
    cout << fixed << setw(6) << setfill('0') << ans << '\n';
}