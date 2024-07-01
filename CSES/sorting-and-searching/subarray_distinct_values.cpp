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

    map<int, int> cub;
    int l = 0;
    int64_t ans = 0;
    for(int r = 0; r < n; ++r){
        cub[arr[r]]++;
        while(cub.size() > k){
            cub[arr[l]]--;
            if(cub[arr[l]] == 0) cub.erase(arr[l]);
            l++;
        }
        ans += max(0, r - l + 1);
    }
    cout << ans << '\n';
}
