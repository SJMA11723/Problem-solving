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
        int n; cin >> n;
        char mat[n][n];
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                cin >> mat[i][j];
                mat[i][j] -= '0';
                if(j) mat[i][j] += mat[i][j - 1];
            }
        }

        bool square = true;
        for(int i = 0; i < n; ++i){
            if(mat[i][n - 1] == 1) square = false;
        }

        if(square) cout << "SQUARE\n";
        else cout << "TRIANGLE\n";
    }
}
