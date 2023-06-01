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
        int n, k; cin >> n >> k;
        int cub[32] = {};
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            int bit = 0;
            while(x){
                cub[bit++] += x % 2;
                x >>= 1;
            }
        }

        int ans = 0;
        for(int i = 30; 0 <= i; --i){
            int dif = n - cub[i];
            if(dif <= k){
                ans += 1 << i;
                k -= dif;
            }
        }
        cout << ans << '\n';
    }
}
