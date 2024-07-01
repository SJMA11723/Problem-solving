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
    int n; int64_t s;
    cin >> n >> s;
    int arr[n];
    for(int &x : arr) cin >> x;

    int l = 0;
    int64_t sum = 0, ans = 0;
    for(int i = 0; i < n; ++i){
        sum += arr[i];
        while(sum - arr[l] >= s) sum -= arr[l++];
        if(sum >= s) ans += l + 1;
    }
    cout << ans << '\n';
}
