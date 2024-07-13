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
        int n, k, a, b;
        cin >> n >> k >> a >> b;
        pair<int64_t, int64_t> points[n];
        for(pair<int64_t, int64_t> &p : points) cin >> p.first >> p.second;

        a--, b--;
        if(b < a) swap(a, b);

        int64_t ans = 0;
        if(k <= b) ans = abs(points[a].first - points[b].first) + abs(points[a].second - points[b].second);

        int64_t dist_a = 1e15, dist_b = 1e15;
        for(int i = 0; i < k; ++i){
            dist_a = min(dist_a, a < k ? 0ll : abs(points[a].first - points[i].first) + abs(points[a].second - points[i].second));
            dist_b = min(dist_b, b < k ? 0ll : abs(points[b].first - points[i].first) + abs(points[b].second - points[i].second));
        }
        ans = min(ans, dist_a + dist_b);

        cout << ans << '\n';
    }
}
