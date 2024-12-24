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
    int n, k; cin >> n >> k;
    string s; cin >> s;
    bool valid[26] = {};
    for(int i = 0; i < k; ++i){
        char c; cin >> c;
        valid[c - 'a'] = true;
    }

    int64_t ans = 0;
    int l = 0, cnt = 0;
    int cub[26] = {};
    for(int r = 0; r < n; ++r){
        cub[s[r] - 'a']++;
        if(!valid[s[r] - 'a'] && cub[s[r] - 'a'] == 1 ) cnt++;
        while(cnt){
            cub[s[l] - 'a']--;
            if(!cub[s[l] - 'a'] && !valid[s[l] - 'a']) cnt--;
            l++;
        }
        ans += max(0, r - l + 1);
    }
    cout << ans << '\n';
}
