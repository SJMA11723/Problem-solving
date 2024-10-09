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
    string card; cin >> card;
    bool ans = false;
    for(int i = 0; i < 5; ++i){
        string s; cin >> s;
        if(s[0] == card[0] || s[1] == card[1]) ans = true;
    }
    cout << (ans ? "YES\n" : "NO\n");
}
