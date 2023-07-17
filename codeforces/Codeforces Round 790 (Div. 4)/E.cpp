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
        int n, q; cin >> n >> q;
        int arr[n];
        for(int i = 0; i < n; ++i) cin >> arr[i];
        sort(arr, arr + n, greater<int>());
        for(int i = 1; i < n; ++i) arr[i] += arr[i - 1];
        while(q--){
            int x; cin >> x;
            int *ptr = lower_bound(arr, arr + n, x);
            if(ptr == arr + n) cout << "-1\n";
            else cout << ptr - arr + 1 << '\n';
        }
    }
}
