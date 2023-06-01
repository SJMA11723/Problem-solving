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
        int n, m; cin >> n >> m;
        char mat[n][m];
        for(int i = 0; i < n; ++i){
            cin >> mat[i];
        }

        for(int j = 0; j < m; ++j){
            int ini = n - 1, fin = n - 1;
            while(0 <= ini && mat[ini][j] != '.') ini--;
            fin = ini - 1;
            while(0 <= fin){
                if(mat[fin][j] == 'o'){
                    ini = fin;
                    while(0 <= ini && mat[ini][j] != '.') ini--;
                    fin = ini - 1;
                } else if(mat[fin][j] == '*') swap(mat[ini--][j], mat[fin--][j]);
                else fin--;
            }
        }

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m ; ++j) cout << mat[i][j];
            cout << '\n';
        }
        cout << '\n';
    }
}
