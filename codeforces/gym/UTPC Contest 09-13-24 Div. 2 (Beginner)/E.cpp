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
    int n, d, x; cin >> n >> d >> x;
    pair<int, int> arr[n];
    for(auto &p : arr) cin >> p.second;
    for(auto &p : arr) cin >> p.first;

    int64_t cnt = 0, ans = 0;
    sort(arr, arr + n, greater<pair<int, int>>());
    for(auto &p : arr){
        if(cnt == 1ll * d * x) break;

        int add = min({1ll*p.second, 1ll*d, 1ll * d * x - cnt});
        ans += 1ll * add * p.first;
        cnt += add;
    }
    cout << ans << '\n';
}
