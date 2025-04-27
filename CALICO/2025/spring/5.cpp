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
        int64_t ul = 0, ur = 0;
        for(char c : s) ur += c == 'u';

        int64_t ans = 0, pending_u = 0;
        for(char c : s){
            if(c == 'u'){
                pending_u++;
                ur--;
                ans += ul;
            } else if(c == 'w'){
                ul += pending_u;
                pending_u = 0;
            }
        }
        cout << ans << '\n';
    }
}
