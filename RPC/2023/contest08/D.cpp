/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

bool mat[105][105];

int contar(int r, int c, int s){
    int res = 0;
    for(int i = r - s; i <= r; ++i){
        for(int j = c - s; j <= c; ++j){
            res += mat[i][j];
        }
    }
    //if(r < 12 && c < 12)cout << r << ' ' << c << ' ' << res << '\n';
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int s, n; cin >> s >> n;

    for(int i = 0; i < n; ++i){
        int x, y;
        cin >> x >> y;
        mat[x][y] = true;
    }

    /*for(int i = 1; i <= 12; ++i){
        for(int j = 1; j <= 12; ++j){
            cout << mat[i][j];
        }
        cout << '\n';
    }*/

    int ans = 0;
    for(int i = s; i <= 100; ++i){
        for(int j = s; j <= 100; ++j){
            ans = max(ans, contar(i, j, s));
        }
    }
    cout << ans << '\n';
}
