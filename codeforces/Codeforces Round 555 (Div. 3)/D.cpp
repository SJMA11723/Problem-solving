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
    int n, k; cin >> n >> k;
    int64_t ans[k]; iota(ans, ans + k, 1);
    int64_t sum = 1ll * k * (k + 1) / 2;

    if(sum > n){
        cout << "NO\n";
        return 0;
    }

    int rem = n - sum;
    for(int i = 0; i < k; ++i) ans[i] += rem / k;
    rem %= k;
    for(int i = k - 1; 0 < i; --i){
        int mini = min({1ll*rem, max(0ll, ans[i - 1] * 2 - ans[i]), (i + 1 < k ? max(0ll, ans[i + 1] - ans[i] - 1) : INT_MAX) });
        ans[i] += mini;
        rem -= mini;
    }

    if(rem){
        cout << "NO\n";
        return 0;
    }

    bool ok = true;
    for(int i = 0; i + 1 < k; ++i) ok = ok && ans[i] < ans[i + 1] && ans[i + 1] <= 2 * ans[i];

    if(!ok){
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    for(int i = 0; i < k; ++i) cout << ans[i] << " \n"[i + 1 == k];
}
