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
        int cnt[2][26];
        memset(cnt, 0, sizeof(cnt));

        for(int i = 0; i < n; ++i) cnt[i % 2][s[i] - 'a']++;
        int ans = n - *max_element(cnt[0], cnt[0] + 26) - *max_element(cnt[1], cnt[1] + 26);

        if(n % 2){
            ans = n;
            for(int i = 0; i < n; ++i){
                cnt[i % 2][s[i] - 'a']--;
                ans = min(ans, n - *max_element(cnt[0], cnt[0] + 26) - *max_element(cnt[1], cnt[1] + 26));
                cnt[!(i % 2)][s[i] - 'a']++;
            }
        }
        cout << ans << '\n';
    }
}
