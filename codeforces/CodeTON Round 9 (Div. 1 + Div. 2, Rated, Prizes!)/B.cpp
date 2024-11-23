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
        int n = s.size();
        string ans = "-1";
        for(int i = 1; i < n; ++i){
            if(s[i] == s[i - 1]){
                ans = string(2, s[i]);
                break;
            }
        }

        if(ans != "-1"){
            cout << ans << '\n';
            continue;
        }

        for(int i = 2; i < n; ++i){
            if(s[i] == s[i - 2]) continue;
            ans = s[i - 2];
            ans += s[i - 1];
            ans += s[i];
            break;
        }
        cout << ans << '\n';
    }
}
