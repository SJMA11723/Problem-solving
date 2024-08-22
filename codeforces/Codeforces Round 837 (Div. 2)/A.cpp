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
        sort(arr, arr + n);

        int cnt_min = 0, cnt_max = 0;
        for(int i = 0; i < n; ++i)
        if(arr[i] == arr[0]) cnt_min++;
        else if(arr[i] == arr[n - 1]) cnt_max++;

        if(arr[0] == arr[n - 1]) cout << 1ll * n * (n - 1) << '\n';
        else cout << 2ll * cnt_max * cnt_min << '\n';
    }
}
