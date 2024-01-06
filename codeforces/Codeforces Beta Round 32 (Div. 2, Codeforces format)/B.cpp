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

    bool code = false;
    for(int i = 0; i < str.size(); ++i){
        if(str[i] == '.'){
            if(code) cout << 1;
            else cout << 0;
            code = false;
        } else if(code) cout << 2, code = false;
        else code = true;
    }
    cout << '\n';
}
