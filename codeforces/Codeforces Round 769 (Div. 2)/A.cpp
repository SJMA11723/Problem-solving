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
        int n; cin >> n;
        string s; cin >> s;
        if(n >= 3) cout << "NO\n";
        else if(n == 1) cout << "YES\n";
        else if(s[0] == s[1]) cout << "NO\n";
        else cout << "YES\n";
    }
}
