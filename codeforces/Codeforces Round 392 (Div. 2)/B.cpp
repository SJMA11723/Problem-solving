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
    string str; cin >> str;
    int cntr, cntb, cnty, cntg = cntb = cntr = cnty = 0;
    string colors; colors.resize(4);
    for(int i = 0; i < str.size(); ++i){
        if(str[i] == '!') continue;
        colors[i % 4] = str[i];
    }

    for(int i = 0; i < str.size(); ++i){
        if(str[i] != '!') continue;
        switch(colors[i % 4]){
            case 'R': cntr++; break;
            case 'B': cntb++; break;
            case 'Y': cnty++; break;
            case 'G': cntg++; break;
        }
    }
    cout << cntr << ' ' << cntb << ' ' << cnty << ' ' << cntg << '\n';
}
