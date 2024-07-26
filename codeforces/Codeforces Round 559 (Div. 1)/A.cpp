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
    int n, m; cin >> n >> m;
    int b[n], g[m];
    for(int &x : b) cin >> x;
    for(int &x : g) cin >> x;
    int maxi_b = *max_element(b, b + n);
    int mini_g = *min_element(g, g + m);

    if(maxi_b > mini_g){
        cout << "-1\n";
        return 0;
    }

    nth_element(b, b + n - 2, b + n);
    int64_t ans = accumulate(b, b + n, 0ll) * m + accumulate(g, g + m, 0ll) - 1ll*(m - 1) * maxi_b - (maxi_b == mini_g ? maxi_b : b[n - 2]);
    cout << ans << '\n';
}
