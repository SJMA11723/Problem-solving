/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define is_on(n, i) ((n) & (1ll << (i)))

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, l, r, x;
    cin >> n >> l >> r >> x;
    int arr[n];
    for(int i = 0; i < n; ++i) cin >> arr[i];

    int ans = 0;
    int lim = 1 << n;
    for(int mask = 0; mask < lim; ++mask){
        int mini = INT_MAX, maxi = 0;
        int dif = 0;
        for(int i = 0; i < n; ++i){
            if(!is_on(mask, i)) continue;
            mini = min(mini, arr[i]);
            maxi = max(maxi, arr[i]);
            dif += arr[i];
        }

        if(l <= dif && dif <= r && x <= maxi - mini) ans++;
    }

    cout << ans << '\n';
}
