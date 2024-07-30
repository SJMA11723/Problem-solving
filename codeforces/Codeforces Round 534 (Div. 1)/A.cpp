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
    string s; cin >> s;
    int v = 0, h = 0;
    for(char c : s){
        if(c == '0'){
            cout << "2 " << v + 1 << '\n';
            v = (v + 1) % 4;
        } else {
            cout << "1 " << 2 * h + 1 << '\n';
            h = (h + 1) % 2;
        }
    }
}
