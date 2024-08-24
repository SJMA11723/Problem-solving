/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int bin_exp(int a, int64_t b, const int MOD){
    if(!b) return 1;
    int tmp = bin_exp(a, b / 2, MOD);
    if(b % 2) return tmp * tmp % MOD * a % MOD;
    return tmp * tmp % MOD;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    int arr[n];
    for(int &x : arr) cin >> x;
    sort(arr, arr + n);

    int cub[m] = {};
    int ans = 1;
    for(int &x : arr){
        x %= m;

        if(cub[x]){ /// aqui principio de casillas
            ans = 0;
            break;
        }

        for(int r = 1; r < m; ++r) ans = ans * bin_exp(r, cub[(x - r + m) % m], m) % m;

        cub[x]++;
    }
    cout << ans << '\n';
}
