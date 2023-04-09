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
    string str[4];
    char c;
    for(int i = 0; i < 4; ++i)
        cin >> c >> c >> str[i];
    int con = 0;
    c = 'C';

    for(int i = 0; i < 4; ++i){
        int shorter = 0, longer = 0;
        for(int j = 0; j < 4; ++j){
            if(i == j) continue;
            if(str[i].size() / 2 >= str[j].size()) longer++;
            if(str[i].size() * 2 <= str[j].size()) shorter++;
        }
        if(shorter == 3 || longer == 3){
            if(con){
                c = 'C';
                break;
            }
            con++;
            c = 'A' + i;
        }
    }

    cout << c;
}
