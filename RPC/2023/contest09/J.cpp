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
    int ds, dm, ys, ym;
    cin >> ds >> ys >> dm >> ym;
    vector<bool> sun(5051);
    for(int i = -ds; i < (int)sun.size(); i += ys)
        if(0 <= i) sun[i] = true;

    for(int i = -dm; i < (int)sun.size(); i += ym){
        if(0 <= i && sun[i]){
            cout << i << '\n';
            return 0;
        }
    }
}
