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
        int arr[n + 1];
        for(int i = 1; i <= n; ++i) cin >> arr[i];
        int64_t ltr[n + 1] = {}, rtl[n + 1] = {};
        ltr[2] = 1;
        for(int i = 3; i <= n; ++i){
            ltr[i] = ltr[i - 1];
            if(arr[i] - arr[i - 1] < arr[i - 1] - arr[i - 2]) ltr[i]++;
            else ltr[i] += (int64_t)(arr[i] - arr[i - 1]);
        }

        rtl[n - 1] = 1;
        for(int i = n - 2; 0 < i; --i){
            rtl[i] = rtl[i + 1];
            if(arr[i + 1] - arr[i] < arr[i + 2] - arr[i + 1]) rtl[i]++;
            else rtl[i] += (int64_t)(arr[i + 1] - arr[i]);
        }

        int m; cin >> m;
        while(m--){
            int x, y; cin >> x >> y;
            if(x < y) cout << ltr[y] - ltr[x] << '\n';
            else cout << rtl[y] - rtl[x] << '\n';
        }
    }
}
