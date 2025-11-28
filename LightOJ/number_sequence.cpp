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

int MOD = 1e9 + 7;

struct matrix{
    int a, b, c, d;

    matrix operator*(const matrix &B){
        return {(a * B.a + b * B.c) % MOD,
                (a * B.b + b * B.d) % MOD,
                (c * B.a + d * B.c) % MOD,
                (c * B.b + d * B.d) % MOD};
    }
};

matrix bin_exp(matrix &A, int n){
    if(!n) return matrix{1, 0, 0, 1};
    matrix tmp = bin_exp(A, n / 2);
    if(n & 1) return tmp * tmp * A;
    return tmp * tmp;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    for(int tt = 1; tt <= t; ++tt){
        int a, b, n, m; cin >> a >> b >> n >> m;
        MOD = 1;
        while(m--) MOD *= 10;

        matrix A{0, 1, 1, 1};
        A = bin_exp(A, n);
        cout << "Case " << tt << ": " << (A.a * a + A.b * b) % MOD << '\n';
    }
}