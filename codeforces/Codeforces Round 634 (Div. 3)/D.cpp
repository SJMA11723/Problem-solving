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
        int col = 0, row = 0;
        for(int i = 0; i < 9; ++i, cout << '\n')
        for(int j = 0; j < 9; ++j){
            char c; cin >> c;
            if(i == row && j == col){
                 cout << char((c - '1' + 1) % 9 + '1');
                 row++;
                 col += 3;
                 if(col >= 9){
                    col = col % 9 + 1;
                 }
            } else cout << c;
        }
    }
}
