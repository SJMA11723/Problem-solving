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
    bool ok = false;
    char mat[n][5];
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < 5; ++j) cin >> mat[i][j];

        if(ok) continue;

        if(mat[i][0] == mat[i][1] && mat[i][1] == 'O'){
            ok = true;
            mat[i][0] = mat[i][1] = '+';
        } else if(mat[i][3] == mat[i][4] && mat[i][4] == 'O'){
            ok = true;
            mat[i][3] = mat[i][4] = '+';
        }
    }

    if(ok){
        cout << "YES\n";
        for(int i = 0; i < n; ++i, cout << '\n')
            for(int j = 0; j < 5; ++j) cout << mat[i][j];
    } else cout << "NO\n";
}
