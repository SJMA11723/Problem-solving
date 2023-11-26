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
    if(str == "Yoda") cout << "Pertenece a Stars Wars.\n";
    else if(str == "Spock") cout << "Pertenece a Star Trek.\n";
    else if(str == "Frodo") cout << "No pertenece ni a Stars Wars ni a Star Trek.\n";
}

