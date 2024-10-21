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
    string yes;
    while(yes.size() < 100) yes += "Yes";

    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        bool ans = false;
        for(int i = (int)s.size(); i < yes.size(); ++i){
            bool ok = true;
            for(int j = 0; j < s.size(); ++j){
                if(s[j] != yes[i - (int)s.size() + j]){
                    ok = false;
                    break;
                }
            }
            if(ok){
                ans = true;
                break;
            }
        }

        cout << (ans ? "YES\n" : "NO\n");
    }
}
