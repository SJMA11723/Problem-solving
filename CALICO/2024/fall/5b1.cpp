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
        int64_t b, n; cin >> b >> n;
        int64_t arr[n];
        for(int64_t &x : arr) cin >> x;
        sort(arr, arr + n);
        int64_t acc[n]; memcpy(acc, arr, sizeof(arr));
        for(int i = 1; i < n; ++i) acc[i] += acc[i - 1];

        int64_t l = 0, r = arr[n - 1];
        while(l < r){
            int64_t mid = l + (r - l) / 2;
            int pos = upper_bound(arr, arr + n, mid) - arr;

            int64_t cost;
            if(pos) cost = acc[n - 1] - acc[pos - 1] - mid * (n - pos);
            else cost = acc[n - 1] - mid * (n - pos);

            if(cost <= b) r = mid;
            else l = mid + 1;
        }

        int pos = upper_bound(arr, arr + n, l) - arr;

        r = *lower_bound(arr, arr + n, l) + 1;
        int64_t ans_danger = 0;
        if(pos) ans_danger = l * pos - acc[pos - 1];

        while(l < r){
            int64_t mid = l + (r - l) / 2;
            pos = upper_bound(arr, arr + n, mid) - arr;

            int64_t danger = 0;
            if(pos) danger = mid * pos - acc[pos - 1];

            if(danger == ans_danger) l = mid + 1;
            else r = mid;
        }
        l--;

        cout << l << '\n';
    }
}
