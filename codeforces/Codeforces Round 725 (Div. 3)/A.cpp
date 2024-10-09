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
        int arr[n];
        for(int &x : arr) cin >> x;
        int pos_min = min_element(arr, arr + n) - arr;
        int pos_max = max_element(arr, arr + n) - arr;
        if(pos_max < pos_min) swap(pos_max, pos_min);
        cout << min({n - pos_max + pos_min + 1, pos_min + 1 + n - pos_max, pos_max + 1, n - pos_min}) << '\n';
    }
}
