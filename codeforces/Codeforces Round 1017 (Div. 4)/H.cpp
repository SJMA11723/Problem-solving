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
        unordered_map<int, vector<int>> idx;
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            idx[x].push_back(i + 1);
        }

        while(q--){
            int k, l, r; cin >> k >> l >> r;

            vector<pair<int, int>> divs;
            for(int i = 1; i * i <= k; ++i){
                int d = i;
                if(k % d) continue;

                if(idx.count(d)){
                    auto lo = lower_bound(idx[d].begin(), idx[d].end(), l);
                    if(lo != idx[d].end() && *lo <= r) divs.push_back({*lo, d});
                }

                d = k / d;
                if(i * i != k && idx.count(d)){
                    auto lo = lower_bound(idx[d].begin(), idx[d].end(), l);
                    if(lo != idx[d].end() && *lo <= r) divs.push_back({*lo, d});
                }
            }

            sort(divs.begin(), divs.end());

            int64_t ans = 0;
            int prv_pos = l - 1;
            for(auto [pos, d] : divs){
                //cout << "deb: " << pos << ' ' << d << ' ' << k << '\n';
                ans += 1ll * (pos - prv_pos - 1) * k;
                //cout << "ans = " << ans << '\n';
                while(k % d == 0) k /= d;
                ans += k;
                //cout << k << ' ' << ans << '\n';
                prv_pos = pos;
            }
            ans += 1ll * (r - prv_pos) * k;
            cout << ans << '\n';
        }
    }
}
