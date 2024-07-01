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
    int n; cin >> n;
    string s; cin >> s;
    bool ap[123] = {};
    for(char c : s) ap[c] = true;
    int k = 0;
    for(int i = 0; i < 123; ++i) if(ap[i]) k++;

    int cub[123] = {};
    int l = 0, cnt = 0, ans = INT_MAX;
    for(int r = 0; r < n; ++r){
        cub[s[r]]++;
        if(cub[s[r]] == 1) cnt++;
        while(cub[s[l]] > 1 && cnt == k) cub[s[l++]]--;
        if(cnt == k) ans = min(ans, r - l + 1);
    }
    cout << ans << '\n';
}
