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
    int64_t n, t, a, b;
    cin >> n >> t >> a >> b;
    int64_t val[n + 1];
    val[0] = 0;
    for(int i = 1; i <= n; ++i){
        cin >> val[i];
        val[i] += val[i - 1];
    }

    int64_t ans = 0;
    for(int64_t i = 0; i < n; ++i){
        int64_t rem_time = max((int64_t)0, t - i * b);
        int l = i, r = n + 1;
        while(l < r){
            int64_t mid = (l + r) / 2;
            if((mid - i) * a <= rem_time) l = mid + 1;
            else r = mid;
        } l--;

        //cout << rem_time << ' ' << l << '\n';
        ans = max(ans, val[l] - val[i]);
    }
    cout << ans << '\n';
}
