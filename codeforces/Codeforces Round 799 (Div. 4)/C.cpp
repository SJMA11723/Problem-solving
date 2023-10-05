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
        char board[8][8];
        for(int i = 0; i < 8; ++i)
            for(int j = 0; j < 8; ++j) cin >> board[i][j];

        for(int i = 1; i < 7; ++i){
            for(int j = 1; j < 7; ++j){
                if(board[i][j] == '#' && board[i - 1][j - 1] == '#' && board[i - 1][j + 1] == '#'
                   && board[i + 1][j + 1] == '#' && board[i + 1][j - 1] == '#'){
                    cout << i + 1 << ' ' << j + 1 << '\n';
                    i = 8;
                    break;
                }
            }
        }
    }
}
