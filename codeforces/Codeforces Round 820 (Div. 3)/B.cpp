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
        reverse(s.begin(), s.end());
        string ans;
        for(int i = 0; i < n; ++i){
            if(s[i] == '0'){
                ans += char(s[i + 1] - '0' + 10 * (s[i + 2] - '0') + 'a' - 1);
                i += 2;
            } else {
                ans += char(s[i] - '0' + 'a' - 1);
            }
        }

        reverse(ans.begin(), ans.end());
        cout << ans << '\n';
    }
}
