/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 7;

struct matrix{
    int64_t a, b, c, d;

    matrix operator*(matrix &o){
        return matrix{(a * o.a % MOD + b * o.c % MOD) % MOD,
                      (a * o.b % MOD + b * o.d % MOD) % MOD,
                      (o.a * c % MOD + d * o.c % MOD) % MOD,
                      (o.b * c % MOD + d * o.d % MOD) % MOD};
    }
};

matrix exp_bin(matrix a, int n){
    if(!n) return matrix{1, 0, 0, 1};

    matrix tmp = exp_bin(a, n / 2);

    if(n % 2) return tmp * tmp * a;
    return tmp * tmp;
}

map<int, int> memo;

int64_t fib(int n){
    if(memo.count(n)) return memo[n];
    return memo[n] = exp_bin({0, 1, 1, 1}, n).b;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    int arr[m];
    for(int i = 0; i < m; ++i) cin >> arr[i];
    sort(arr, arr + m);

    int64_t ans = 1;
    int l = 0;
    for(int i = 0; i < m; ++i){
        ans *= fib(arr[i] - l);
        ans %= MOD;
        l = arr[i] + 1;
    }

    ans *= fib(n - l + 1);
    ans %= MOD;

    cout << ans << '\n';
}
