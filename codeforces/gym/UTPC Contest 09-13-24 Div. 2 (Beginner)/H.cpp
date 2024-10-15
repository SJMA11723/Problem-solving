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
    int n, q; cin >> n >> q;
    int arr[n], arr2[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        arr2[i] = n - arr[i];
    }
    sort(arr, arr + n);
    sort(arr2, arr2 + n);

    while(q--){
        int t; cin >> t;
        int l = 0, r = n;
        while(l < r){
            int mid = (l + r) / 2;
            if(arr[mid] <= t) l = mid + 1;
            else r = mid;
        }
        int left = l;

        l = 0, r = n;
        while(l < r){
            int mid = (l + r) / 2;
            if(arr2[mid] <= t) l = mid + 1;
            else r = mid;
        }

        int right = l;
        if(n - right - left < 0) cout << "-1\n";
        else cout << right + left << '\n';
    }
}
