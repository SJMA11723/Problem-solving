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
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    cout << "50 50\n";
    char ans[50][50];
    for(int i = 0; i < 25; ++i)
        for(int j = 0; j < 50; ++j) ans[i][j] = 'A';
    for(int i = 25; i < 50; ++i)
        for(int j = 0; j < 50; ++j) ans[i][j] = 'B';
    a--;
    b--;

    for(int j = 0; j < 50; j += 2)
    for(int i = 0; i < 24; ++i){
        if(b && (i == 0 || ans[i - 1][j] != 'B')) ans[i][j] = 'B', b--;
        else if(c && (i == 0 || ans[i - 1][j] != 'C')) ans[i][j] = 'C', c--;
        else if(d && (i == 0 || ans[i - 1][j] != 'D')) ans[i][j] = 'D', d--;
    }

    for(int j = 0; j < 50; j += 2)
    for(int i = 49; 25 < i; --i){
        if(a && (i == 49 || ans[i + 1][j] != 'A')) ans[i][j] = 'A', a--;
        else if(c && (i == 49 || ans[i + 1][j] != 'C')) ans[i][j] = 'C', c--;
        else if(d && (i == 49 || ans[i + 1][j] != 'D')) ans[i][j] = 'D', d--;
    }

    for(int i = 0; i < 50; ++i, cout << '\n')
        for(int j = 0; j < 50; ++j) cout << ans[i][j];
}
