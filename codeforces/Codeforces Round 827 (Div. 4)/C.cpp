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
        char ans = 0;
        for(int i = 0; i < 8; ++i){
            int cnt = 0;
            for(int j = 0; j < 8; ++j){
                cin >> mat[i][j];
                if(mat[i][j] == 'R') cnt++;
            }
            if(cnt == 8) ans = 'R';
        }

        if(ans){
            cout << ans << '\n';
            continue;
        }

        for(int i = 0; i < 8; ++i){
            int cnt = 0;
            for(int j = 0; j < 8; ++j)
                if(mat[j][i] == 'B') cnt++;
            if(cnt == 8) ans = 'B';
        }

        cout << ans << '\n';
    }
}
