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
        int64_t m; cin >> m;
        pair<int64_t, int64_t> arr[n];
        for(pair<int64_t, int64_t> &p : arr) cin >> p.first;
        for(pair<int64_t, int64_t> &p : arr) cin >> p.second;

        sort(arr, arr + n);
        int64_t ans = min(m / arr[n - 1].first, 1ll*arr[n - 1].second) * arr[n - 1].first;
        for(int i = 0; i < n - 1; ++i){
            int64_t f1 = min(m / arr[i].first, 1ll*arr[i].second) * arr[i].first;
            ans = max(ans, f1);

            if(arr[i].first + 1 != arr[i + 1].first) continue;

            int64_t a, cnt_a, cnt_nxt = arr[i + 1].second;
            tie(a, cnt_a) = arr[i];

            int64_t f2 = min((m - f1) / (a + 1), cnt_nxt) * (a + 1);
            ans = max(ans, f1 + f2);

            int64_t r = m - f1 - f2;
            int64_t rep = min({f1/a, cnt_nxt - f2 / (a + 1), r});
            ans = max(ans, f1 + f2 + rep);
        }

        cout << ans << '\n';
    }
}
