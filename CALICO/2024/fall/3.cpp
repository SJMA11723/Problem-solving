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
            for(int j = 0; j < m; ++j){
                cin >> mat[i][j];
            }
        }

        bool rectangle = true;
        for(int i = 0; i < n; ++i){
            int first = -1;
            int last = -1;
            for(int j = 0; j < m; ++j){
                if(mat[i][j] == '#'){
                    if(first == -1) first = j;
                    last = j;
                }
            }

            if(first == -1) continue;

            int last_r = -1;
            for(int r = i; r < n; ++r) if(mat[r][first] == '#') last_r = r;

            for(int r = 0; r < n; ++r){
                for(int c = 0; c < m; ++c){
                    if(i <= r && r <= last_r && first <= c && c <= last){
                        if(mat[r][c] == '.') rectangle = false;
                    } else {
                        if(mat[r][c] == '#') rectangle = false;
                    }
                }
            }

            break;
        }

        cout << (rectangle ? "ferb\n" : "phineas\n");
    }
}
