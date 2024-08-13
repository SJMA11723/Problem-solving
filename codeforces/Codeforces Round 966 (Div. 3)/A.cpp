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
        string s; cin >> s;
        if(s.size() < 3){
            cout << "NO\n";
            continue;
        }

        if(s[0] != '1' || s[1] != '0'){
            cout << "NO\n";
            continue;
        }

        string exponent = s.substr(2);
        if(exponent[0] == '0' || stoi(exponent) < 2){
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
    }
}
