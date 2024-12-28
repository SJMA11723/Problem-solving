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
        int n, m; cin >> n >> m;
        int cnt[26][n];
        memset(cnt, 0, sizeof(cnt));
        string s; cin >> s;
        for(int i = 0; i < n; ++i) cnt[s[i] - 'a'][i]++;

        for(int i = 1; i < n; ++i){
            for(int j = 0; j < 26; ++j){
                cnt[j][i] += cnt[j][i - 1];
            }
        }

        int ans[26] = {};
        for(int i = 0; i < m; ++i){
            int x; cin >> x;
            x--;
            for(int j = 0; j < 26; ++j) ans[j] += cnt[j][x];
        }

        for(int j = 0; j < 26; ++j) ans[j] += cnt[j][n - 1];

        for(int i = 0; i < 26; ++i) cout << ans[i] << " \n"[i == 25];
    }
}
