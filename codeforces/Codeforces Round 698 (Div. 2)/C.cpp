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
        n *= 2;
        int64_t d[n];
        for(int64_t &x : d) cin >> x;

        sort(d, d + n, greater<int64_t>());
        bool ok = true;
        for(int i = 0; i < (n>>1); ++i) ok = ok && d[2 * i] == d[2 * i + 1];
        int N = unique(d, d + n) - d;
        n /= 2;
        ok = ok && n == N && d[0] % (2 * n) == 0;

        int64_t cur = -d[0] / (2 * n);
        ok = ok && cur < 0;
        for(int i = 0; i + 1 < n && ok; ++i){
            int64_t diff = abs(d[i] - d[i + 1]);
            if(diff % (2 * (i + 1 - n))){
                ok = false;
                break;
            }
            diff /= abs((2 * (i + 1 - n)));
            cur += diff;
            ok = ok && cur < 0;
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
}
