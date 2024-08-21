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
    int n; cin >> n;
    for(int i = 1; i <= n; ++i){
        int64_t ans = 4ll * (i * i - 2 - 1); /// esquinas
        ans += 8ll * (i * i - 3 - 1); /// casillas a un lado de las esquinas
        ans += 4ll * (i - 4) * (i * i - 4 - 1); /// resto de la capa exterior
        ans += 4ll * (i * i - 4 - 1); /// esquinas de la segunda capa
        ans += 4ll * (i - 4) * (i * i - 6 - 1); /// resto de la segunda capa
        ans += 1ll * (i - 4) * (i - 4) * (i * i - 8 - 1); /// resto del tablero
        ans /= 2;
        cout << ans << '\n';
    }
}
