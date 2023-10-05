/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ull;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        ull c, r, s;
        cin >> c >> r >> s;

        ull r_maxi = r % s, c_maxi;
        ull maxi = c / s;

        c_maxi = max(c % s - (s - r_maxi) % s, 0ll);

        maxi += (c_maxi + s - 1) / s;
        ull mini = 0;

        ull cucharadasTotales = (c + r + s - 1) / s;

        //if( cucharadasTotales <= r ) mini = 0;
        //else
        if(r * (s - 1) <= c) mini = (c - r * (s - 1) + s - 1) / s;
        else mini = 0;
        cout << maxi << ' ' << mini << '\n';
    }
}
