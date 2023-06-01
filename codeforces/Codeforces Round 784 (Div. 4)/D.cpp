/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

char inv(char c){
    if(c == 'R') return 'B';
    return 'R';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string str; cin >> str;
        bool ok = true, iguales = true;
        for(int i = 1; i < n; ++i){
            if(str[i] == 'W'){
                if(str[i - 1] != 'W' && iguales) ok = false;
                iguales = true;
            } else if(str[i - 1] != 'W' && str[i] != str[i - 1]) iguales = false;
        }

        if(str.back() != 'W' && iguales) ok = false;

        if(ok) cout << "yes\n";
        else cout << "no\n";
    }
}
