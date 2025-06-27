/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

bool vowel(char c){
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string str; cin >> str;
    bool ok = true;
    for(int i = 0; i < str.size(); ++i){
        if(i + 1 == str.size()) continue;
        if( (vowel(str[i]) && vowel(str[i + 1])) || (!vowel(str[i]) && !vowel(str[i + 1])) ) ok = false;
    }
    cout << ok << '\n';
}
