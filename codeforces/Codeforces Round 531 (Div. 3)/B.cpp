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
    pair<int, int> arr[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr, arr + n);

    bool ok = true;
    int prv = 0, idx_color = 0, first = 0;
    int ans[n];
    for(auto [c, i] : arr){
        if(c == prv){
            ans[i] = ++idx_color;
            if(idx_color == first) ok = false;
            if(idx_color == k) idx_color = 0;
        } else {
            prv = c;
            ans[i] = ++idx_color;
            first = idx_color;
            if(idx_color == k) idx_color = 0;
        }
    }

    if(ok){
        cout << "YES\n";
        for(int i = 0; i < n; ++i) cout << ans[i] << " \n"[i + 1 == n];
    } else cout << "NO\n";
}
