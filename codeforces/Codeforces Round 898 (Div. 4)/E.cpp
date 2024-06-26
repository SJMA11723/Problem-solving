/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int64_t water(int n, int arr[], int h){
    int64_t res = 1ll * h * n;
    for(int i = 0; i < n; ++i) res -= min(h, arr[i]);
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, x; cin >> n >> x;
        int arr[n];
        for(int i = 0; i < n; ++i) cin >> arr[i];

        int l = 0, r = INT_MAX;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(water(n, arr, mid) > x) r = mid;
            else l = mid + 1;
        }
        cout << l - 1 << '\n';
    }
}
