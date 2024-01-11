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
        string code = "codeforces";
        int ans = 0;
        for(int i = 0; i < 10; ++i)
            if(s[i] != code[i]) ans++;
        cout << ans << '\n';
    }
}
