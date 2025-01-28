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
    long double arr[n];
    for(long double &x : arr) cin >> x;
    sort(arr, arr + n);
    long double prob = arr[n - 1], prob_c = 1 - arr[n - 1], ans = arr[n - 1];
    for(int i = n - 2; 0 <= i; --i){
        prob = (1 - arr[i]) * prob + arr[i] * prob_c;
        prob_c *= 1 - arr[i];
        ans = max(ans, prob);
    }
    cout << fixed << setprecision(12) << ans << '\n';
}
