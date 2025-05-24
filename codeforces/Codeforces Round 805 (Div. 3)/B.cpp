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
        int l = 0, letters = 0, ans = 1;
        int cnt[26] = {};
        for(int r = 0; r < n; ++r){
            cnt[s[r] - 'a']++;
            if(cnt[s[r] - 'a'] == 1) letters++;
            if(letters > 3){
                ans++;
                while(l < r){
                    cnt[s[l] - 'a']--;
                    if(!cnt[s[l] - 'a']) letters--;
                    l++;
                }
            }
        }
        cout << ans << '\n';
    }
}
