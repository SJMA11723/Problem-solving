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
        int cnt[26] = {};
        for(char c : s) cnt[c - 'a']++;
        int ans = 0, single = 0;
        for(int i = 0; i < 26; ++i)
            if(cnt[i] > 1) ans++;
            else if(cnt[i] == 1) single++;
        cout << ans + single / 2 << '\n';
    }
}
