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
    stack<char> pila;
    for(int i = 0; i < str.size(); ++i){
        while(pila.size() && pila.top() >= str[i]){
            pila.pop();
        }
        pila.push(str[i]);

        if(pila.size() < 2) cout << "Mike\n";
        else cout << "Ann\n";
    }
}
