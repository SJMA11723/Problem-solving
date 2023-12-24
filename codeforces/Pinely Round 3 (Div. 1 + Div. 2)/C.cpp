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
        int64_t r[n], c[n];
        set<int64_t> l;
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            l.insert(x);
        }
        for(int i = 0; i < n; ++i) cin >> r[i];
        for(int i = 0; i < n; ++i) cin >> c[i];
        sort(r, r + n);
        sort(c, c + n, greater<int64_t>());

        for(int i = 0; i < n; ++i){
            auto it = l.lower_bound(r[i]);
            it--;
            r[i] -= *it;
            l.erase(it);
        }

        sort(r, r + n);
        int64_t ans = 0;
        for(int i = 0; i < n; ++i) ans += r[i] * c[i];
        cout << ans << '\n';
    }
}
