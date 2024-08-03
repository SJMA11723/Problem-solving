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
    int a, b, c; cin >> a >> b >> c;
    int weeks = min({a / 3, b / 2, c / 2});
    a -= weeks * 3;
    b -= weeks * 2;
    c -= weeks * 2;

    int acc[14][3];
    memset(acc, 0, sizeof(acc));
    acc[0][0] = acc[7][0] = 1;
    acc[3][0] = acc[10][0] = 1;
    acc[6][0] = acc[13][0] = 1;

    acc[1][1] = acc[8][1] = 1;
    acc[5][1] = acc[12][1] = 1;

    acc[2][2] = acc[9][2] = 1;
    acc[4][2] = acc[11][2] = 1;

    int ans = 0;
    for(int i = 0; i < 7; ++i){
        int na = a, nb = b, nc = c;
        for(int j = i; j < i + 7; ++j){
            na -= acc[j][0];
            nb -= acc[j][1];
            nc -= acc[j][2];
            if(na < 0 || nb < 0 || nc < 0) break;
            ans = max(ans, j - i + 1);
        }
    }
    ans += weeks * 7;
    cout << ans << '\n';
}
