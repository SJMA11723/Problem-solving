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

    int ans = 0, l = 0;
    for(int r = 0; r < n; ++r){
        while(l < r && arr[r] - arr[l] > 5) l++;
        ans = max(ans, r - l + 1);
    }
    cout << ans << '\n';
}
