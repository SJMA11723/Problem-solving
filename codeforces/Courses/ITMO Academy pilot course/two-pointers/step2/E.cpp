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
    int arr[n];
    for(int &x : arr) cin >> x;

    int cub[100001] = {};
    int l = 0, cnt = 0;
    int64_t ans = 0;
    for(int i = 0; i < n; ++i){
        cub[arr[i]]++;
        if(cub[arr[i]] == 1) cnt++;

        while(cnt > k){
            cub[arr[l]]--;
            if(!cub[arr[l]]) cnt--;
            l++;
        }
        ans += i - l + 1;
    }
    cout << ans << '\n';
}
