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
    int n; cin >> n;
    int arr[n];
    for(int &x : arr) cin >> x;
    sort(arr, arr + n);
    int64_t ans = 0;
    for(int i = 0; i < n; ++i) ans += abs(arr[i] - arr[n / 2]);
    cout << ans << '\n';
}
