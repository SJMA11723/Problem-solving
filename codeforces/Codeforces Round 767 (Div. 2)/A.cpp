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
        int n, k; cin >> n >> k;
        pair<int, int> arr[n];
        for(auto &[f, s] : arr) cin >> f;
        for(auto &[f, s] : arr) cin >> s;
        sort(arr, arr + n);
        for(auto &[f, s] : arr)
            if(f <= k) k += s;
        cout << k << '\n';
    }
}
