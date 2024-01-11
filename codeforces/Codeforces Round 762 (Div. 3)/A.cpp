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
        int n = str.size();
        if(str.substr(0, n / 2) == str.substr(n / 2)) cout << "YES\n";
        else cout << "NO\n";
    }
}
