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
        cout << s[1] - 'a' + 1 + (s[0] - 'a') * ('z' - 'a') - (s[0] <= s[1]) << '\n';
    }
}
