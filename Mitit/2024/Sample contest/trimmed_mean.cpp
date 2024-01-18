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
    int arr[5 * n];
    for(int i = 0; i < 5 * n; ++i) cin >> arr[i];
    sort(arr, arr + 5 * n);
    double ans  = 0;
    for(int i = n; i < 4 * n; ++i) ans += arr[i];
    ans /= 3 * n;
    cout << fixed << setprecision(6) << ans << '\n';
}
