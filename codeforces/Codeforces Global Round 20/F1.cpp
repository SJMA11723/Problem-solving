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
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        pair<int, int> arr[n];
        int cnt[n] = {};
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            arr[i] = {x, i};
            cnt[x]++;
        }
        int maxi = *max_element(cnt, cnt + n);
        sort(arr, arr + n);

        int ans[n];
        for(int i = 0; i < n; ++i) ans[ arr[i].second ] = arr[(i + maxi) % n].first;

        for(int i = 0; i < n; ++i) cout << ans[i] << " \n"[i + 1 == n];
    }
}
