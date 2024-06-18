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
        int ans = 0, cur = 1;
        for(char c : s){
            int d = c - '0';
            if(!d) d = 10;
            ans += abs(cur - d) + 1;
            cur = d;
        }
        cout << ans << '\n';
    }
}
