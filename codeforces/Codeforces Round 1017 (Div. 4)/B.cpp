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
        int n, m, l, r;
        cin >> n >> m >> l >> r;
        m = n - m;
        int cnt = min(m, -l);
        m -= cnt;
        l += cnt;
        cnt = min(m, r);
        r -= cnt;
        cout << l << ' ' << r << '\n';
    }
}
