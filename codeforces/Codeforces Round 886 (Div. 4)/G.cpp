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
        map<int, int> xs, ys, diff, sum;
        int64_t ans = 0;
        for(int i = 0; i < n; ++i){
            int x, y; cin >> x >> y;
            ans += 2ll * (xs[x] + ys[y] + diff[x - y] + sum[x + y]);
            xs[x]++;
            ys[y]++;
            diff[x - y]++;
            sum[x + y]++;
        }
        cout << ans << '\n';
    }
}
