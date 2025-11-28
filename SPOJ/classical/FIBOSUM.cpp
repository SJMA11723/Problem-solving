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

const int MOD = 1e9 + 7;

struct matrix{
    int a, b, c, d;

    matrix operator*(const matrix &B){
        return {(1ll * a * B.a + 1ll * b * B.c) % MOD,
                (1ll * a * B.b + 1ll * b * B.d) % MOD,
                (1ll * c * B.a + 1ll * d * B.c) % MOD,
                (1ll * c * B.b + 1ll * d * B.d) % MOD};
    }
};

matrix bin_exp(matrix &A, int n){
    if(!n) return matrix{1, 0, 0, 1};
    matrix tmp = bin_exp(A, n / 2);
    if(n & 1) return tmp * tmp * A;
    return tmp * tmp;
}

int fibo(int n){
    matrix A{0, 1, 1, 1};
    A = bin_exp(A, n);
    return A.b;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        cout << (fibo(m + 2) - fibo(n + 1) + MOD) % MOD << '\n';
    }
}