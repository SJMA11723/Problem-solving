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
    int64_t s;
    int n; cin >> n >> s;
    int arr[n];
    for(int &x : arr) cin >> x;

    int l = 0, ans = 0;
    int64_t sum = 0;
    for(int i = 0; i < n; ++i){
        sum += arr[i];
        while(sum > s) sum -= arr[l++];
        ans = max(ans, i - l + 1);
    }
    cout << ans << '\n';
}
