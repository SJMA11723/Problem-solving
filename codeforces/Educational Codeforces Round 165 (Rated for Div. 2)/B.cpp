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
        int64_t ans = 0;
        int cnt = 0;
        for(int i = 0; i < n; ++i){
            if(s[i] == '1') cnt++;
            else if(cnt) ans += cnt + 1;
        }
        cout << ans << '\n';
    }
}
