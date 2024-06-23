/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    int mat[n][m];
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            int x; cin >> x; x--;
            mat[i][j] = x;
        }
    }

    int64_t ans = 0;
    bitset<2000> parejas[2000];
    for(int i = 0; i < m; ++i){
        bitset<2000> sets[999];
        for(int j = 0; j < n; ++j) sets[mat[j][i]].set(j);

        for(int j = 0; j < n; ++j) parejas[j] ^= sets[ mat[j][i] ];
    }

    for(int i = 0; i < n; ++i) ans += 1ll * parejas[i].count();

    if(m % 2) ans -= n; /// no contamos las parejas (i, i). Como m es impar, cumple la condicion de paridad para valores iguales

    cout << ans / 2 << '\n';
}
