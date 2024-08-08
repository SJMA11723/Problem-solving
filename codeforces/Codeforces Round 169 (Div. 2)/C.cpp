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
    int n, q; cin >> n >> q;
    int arr[n];
    for(int &x : arr) cin >> x;

    int acc[n + 1] = {};
    while(q--){
        int l, r; cin >> l >> r;
        l--, r--;
        acc[l]++;
        acc[r + 1]--;
    }

    for(int i = 1; i < n; ++i) acc[i] += acc[i - 1];
    sort(acc, acc + n);
    sort(arr, arr + n);
    int64_t ans = 0;
    for(int i = 0; i < n; ++i) ans += 1ll * acc[i] * arr[i];
    cout << ans << '\n';
}
