/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define is_power_of_two(S) (!((S) & ((S) - 1)))

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int64_t n, k; cin >> n >> k;
        int cub[64] = {};
        for(int i = 0; i < n; ++i){
            int64_t x; cin >> x;
            int cnt = 0;
            while(x){
                cub[cnt++] += x % k;
                x /= k;
            }
        }

        bool ok = true;
        for(int i = 0; i < 64; ++i)
            if(cub[i] > 1) ok = false;
        cout << (ok ? "YES\n" : "NO\n");
    }
}
