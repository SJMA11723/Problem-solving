/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

char inv(char c){
    if(c == '1') return '0';
    return '1';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string str; cin >> str;
        int ini = 0, fin = n - 1;
        for(; ini < n && ini <= fin; ++ini){
            if(str[ini] == inv(str[fin])) fin--;
            else break;
        }
        cout << max(0, fin - ini + 1) << '\n';
    }
}
