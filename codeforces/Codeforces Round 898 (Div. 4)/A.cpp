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
        string str; cin >> str;
        for(int i = 0; i < 3; ++i){
            if(str[i] != 'a' + i){
                swap(str[i], str[str[i] - 'a']);
                break;
            }
        }
        cout << (str == "abc" ? "YES\n" : "NO\n");
    }
}
