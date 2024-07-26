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
        int n, q; cin >> n >> q;
        int cnt_a[n + 1][26], cnt_b[n + 1][26];
        memset(cnt_a, 0, sizeof(cnt_a));
        memset(cnt_b, 0, sizeof(cnt_b));

        for(int i = 1; i <= n; ++i){
            char c; cin >> c;
            cnt_a[i][c - 'a']++;
            for(int j = 0; j < 26; ++j) cnt_a[i][j] += cnt_a[i - 1][j];
        }

        for(int i = 1; i <= n; ++i){
            char c; cin >> c;
            cnt_b[i][c - 'a']++;
            for(int j = 0; j < 26; ++j) cnt_b[i][j] += cnt_b[i - 1][j];
        }

        while(q--){
            int l, r; cin >> l >> r;
            int ans = 0, sum = 0;
            for(int j = 0; j < 26; ++j){
                int diff = cnt_a[r][j] - cnt_a[l - 1][j] - cnt_b[r][j] + cnt_b[l - 1][j];
                if(!diff) continue;

                if(diff > 0){
                    if(sum < 0) ans += min(diff, abs(sum));
                } else {
                    if(sum > 0) ans += min(sum, abs(diff));
                }

                sum += diff;
            }
            ans += abs(sum);
            cout << ans << '\n';
        }
    }
}
