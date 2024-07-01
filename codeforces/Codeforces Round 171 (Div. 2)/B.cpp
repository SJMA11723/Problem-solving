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
    int n, t; cin >> n >> t;
    int arr[n];
    for(int &x : arr) cin >> x;

    int l = 0, ans = 0, sum = 0;
    for(int r = 0; r < n; ++r){
        sum += arr[r];
        while(sum > t) sum -= arr[l++];
        ans = max(ans, r - l + 1);
    }
    cout << ans << '\n';
}
