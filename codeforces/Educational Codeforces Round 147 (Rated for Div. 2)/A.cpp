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
        if(s[0] == '0'){
            cout << "0\n";
            continue;
        }

        int ans = 1;
        for(int i = 0; i < s.size(); ++i)
            if(s[i] == '?') ans *= 9 + (i != 0);
        cout << ans << '\n';
    }
}
