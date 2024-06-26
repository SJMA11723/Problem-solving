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
        int ans = 0;

        for(char c : s) ans += c == 'A';

        if(s[0] == 'A' && s[n - 1] == 'A'){
            int mini = INT_MAX;
            int cnt = 0;
            for(int i = 0; i < n; ++i){
                if(s[i] == 'A') cnt++;
                else {
                    mini = min(mini, cnt);
                    cnt = 0;
                }
            }
            mini = min(mini, cnt);
            ans -= mini;
        }

        cout << ans << '\n';
    }
}
