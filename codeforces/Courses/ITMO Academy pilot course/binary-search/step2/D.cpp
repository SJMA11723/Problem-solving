/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int64_t ballons(int n, int64_t t[], int64_t z[], int64_t y[], const int64_t time){
    int64_t res = 0;
    for(int i = 0; i < n; ++i) res += time / (t[i] * z[i] + y[i]) * z[i] + min(time % (t[i] * z[i] + y[i]) / t[i], z[i]);
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int64_t m, n; cin >> m >> n;
    int64_t t[n], z[n], y[n];
    for(int i = 0; i < n; ++i) cin >> t[i] >> z[i] >> y[i];

    int64_t l = 0, r = 2'501'500'000'000;
    while(l < r){
        int64_t mid = l + (r - l) / 2;
        if(ballons(n, t, z, y, mid) >= m) r = mid;
        else l = mid + 1;
    }

    int64_t cnt = 0;
    int64_t ans[n];
    for(int i = 0; i < n; ++i){
        ans[i] = l / (t[i] * z[i] + y[i]) * z[i] + min(l % (t[i] * z[i] + y[i]) / t[i], z[i]);
        cnt += ans[i];
    }

    cnt -= m;
    for(int i = 0; i < n; ++i){
        int64_t mini = min(cnt, ans[i]);
        cnt -= mini;
        ans[i] -= mini;
    }

    cout << l << '\n';
    for(int i = 0; i < n; ++i) cout << ans[i] << " \n"[i + 1 == n];
}
