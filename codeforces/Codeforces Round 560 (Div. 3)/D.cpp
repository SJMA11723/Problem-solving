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
        int div[n];
        for(int &d : div) cin >> d;
        sort(div, div + n);
        int64_t x = 1ll * div[0] * div[n - 1];
        bool ok = true;
        for(int i = 0; i < n / 2; ++i) ok = ok && (1ll * div[i] * div[n - 1 - i] == x);
        if(n % 2) ok = ok && (1ll * div[n / 2] * div[n / 2] == x);

        int64_t cnt_div = 0;
        for(int64_t i = 2; i * i <= x; ++i){
            if(x % i) continue;
            cnt_div++;
            if(i * i != x) cnt_div++;
        }

        ok = ok && cnt_div == n;

        cout << (ok ? x : -1) << '\n';
    }
}
