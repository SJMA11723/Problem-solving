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
        int64_t k, l, r, ll, rr;
        cin >> k >> l >> r >> ll >> rr;
        int64_t powk = 1, ans = 0;
        for(int i = 0; powk <= rr; ++i, powk *= k){
            int64_t multl = (ll - 1) / powk + 1;
            int64_t multr = rr / powk;
            ans += max(0ll, min(r, multr) - max(l, multl) + 1);
        }
        cout << ans << '\n';
    }
}
