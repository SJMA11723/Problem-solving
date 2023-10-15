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
        string str;
        bool ok = false, dos = false, tres = false;
        cin >> str;

        int suma = 0;
        for(char c : str) suma += c - '0';

        if( (str.back() - '0') % 2 == 0 ){
            cout << "2";
            ok = dos = true;
        }

        if(suma % 3 == 0){
            if(ok) cout << " ";
            cout << "3";
            ok = tres = true;
        }

        if(str.size() == 1 && (str.back() - '0') % 4 == 0){
            if(ok) cout << " ";
            cout << "4";
            ok = true;
        } else if(str.size() > 1 && (str.back() - '0' + (str[str.size() - 2] - '0') * 10) % 4 == 0){
            if(ok) cout << " ";
            cout << "4";
            ok = true;
        }

        if( (str.back() - '0') % 5 == 0 ){
            if(ok) cout << " ";
            cout << "5";
            ok = true;
        }

        if(dos && tres){
            if(ok) cout << " ";
            cout << "6";
            ok = true;
        }
        if(!ok) cout << "-1";

        cout << '\n';
    }
}
