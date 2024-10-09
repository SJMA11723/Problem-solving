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
        string alph; cin >> alph;
        short pos[26] ;
        for(int i = 0; i < alph.size(); ++i) pos[alph[i] - 'a'] = i;

        string s; cin >> s;
        short prv = pos[s[0] - 'a'];
        short ans = 0;
        for(char c : s){
            ans += abs(pos[c - 'a'] - prv);
            prv = pos[c  - 'a'];
        }
        cout << ans << '\n';
    }
}
