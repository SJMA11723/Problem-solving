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
    int board[n][5][5];
    string names[n];
    for(int i = 0; i < n; ++i){
        cin >> names[i];
        for(int j = 0; j < 5; ++j)
            for(int k = 0; k < 5; ++k)
                cin >> board[i][j][k];
    }

    int m; cin >> m;
    set<int> balls;
    for(int i = 0; i < m; ++i){
        int b; cin >> b;
        balls.insert(b);
    }

    bool winner[n] = {};
    for(int i = 0; i < n; ++i){
        int cnt_d1 = 0, cnt_d2 = 0;
        for(int j = 0; j < 5; ++j){
            int cnt_r = 0, cnt_c = 0;
            for(int k = 0; k < 5; ++k){
                cnt_c += balls.count(board[i][k][j]);
                cnt_r += balls.count(board[i][j][k]);
            }
            if(cnt_c == 5 || cnt_r == 5)
                winner[i] = true;

            cnt_d1 += balls.count(board[i][j][j]);
            cnt_d2 += balls.count(board[i][4 - j][j]);
        }
        if(cnt_d1 == 5 || cnt_d2 == 5)
            winner[i] = true;
    }

    int cnt_w = 0;
    for(int i = 0; i < n; ++i) cnt_w += winner[i];

    cout << cnt_w << '\n';
    for(int i = 0; i < n; ++i)
        if(winner[i]) cout << names[i] << '\n';
}
