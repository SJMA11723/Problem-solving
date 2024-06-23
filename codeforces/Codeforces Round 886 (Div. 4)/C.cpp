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
        char mat[8][8];
        string ans;
        for(int i = 0; i < 8; ++i)
            for(int j = 0; j < 8; ++j) cin >> mat[i][j];

        for(int i = 0; i < 8; ++i){
            for(int j = 0; j < 8; ++j)
                if(mat[j][i] != '.') ans += mat[j][i];
            if(ans.size()) break;
        }
        cout << ans << '\n';
    }
}
