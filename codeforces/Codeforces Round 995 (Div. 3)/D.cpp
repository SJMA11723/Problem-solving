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
        int64_t x, y; cin >> x >> y;
        int a[n];
        for(int &x : a) cin >> x;
        sort(a, a + n, greater<int>());
        int64_t sum = accumulate(a, a + n, 0ll);

        int64_t ans = 0;
        for(int i = 0; i + 1 < n; ++i){
            int l = i + 1, r = n;
            while(l < r){
                int mid = l + (r - l) / 2;
                int64_t sum2 = sum - a[i] - a[mid];
                if(x <= sum2) r = mid;
                else l = mid + 1;
            }
            int lo = l;

            l = i + 1, r = n;
            while(l < r){
                int mid = l + (r - l) / 2;
                int64_t sum2 = sum - a[i] - a[mid];
                if(sum2 <= y) l = mid + 1;
                else r = mid;
            }
            int hi = r - 1;
            ans += hi - lo + 1;
        }
        cout << ans << '\n';
    }
}
