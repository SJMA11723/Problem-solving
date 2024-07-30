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
        char prv = 0;
        bool printed = false;
        for(char c : s){
            if(prv == c){
                if(!printed) cout << (c == 'a' ? 'b' : 'a');
                printed = true;
            }
            cout << c;
            prv = c;
        }
        if(!printed) cout << (prv == 'a' ? 'b' : 'a');
        cout << '\n';
    }
}
