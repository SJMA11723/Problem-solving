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
    int t; cin >> t;
    while(t--){
        int a, b, xk, yk, xq, yq;
        cin >> a >> b >> xk >> yk >> xq >> yq;
        int dir_i[8] = {a, a, b, -b, -a, -a, -b, b},
            dir_j[8] = {-b, b, a, a, b, -b, -a, -a};
        set<pair<int, int>> visitado;
        int ans = 0;
        for(int i = 0; i < 8; ++i){
            int nx = xk + dir_i[i];
            int ny = yk + dir_j[i];
            if(visitado.count({nx, ny})) continue;
            visitado.insert({nx, ny});
            for(int j = 0; j < 8; ++j){
                if(nx + dir_i[j] == xq && ny + dir_j[j] == yq){
                    ans++;
                    break;
                }
            }
        }
        cout << ans << '\n';
    }
}
