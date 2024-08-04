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
        int64_t n, k; cin >> n >> k;
        int maxi = 0;
        int acc[2 * k + 1] = {};
        for(int i = 0; i < n; ++i){
            int a; cin >> a;
            maxi = max(maxi, a);
            int l = a % (2 * k), r = (a + k) % (2 * k);
            acc[l]++;
            acc[r]--;
            if(r < l) acc[0]++;
        }

        for(int i = 1; i < 2 * k; ++i) acc[i] += acc[i - 1];

        int ans = -1;
        for(int i = maxi; i < maxi + 2 * k; ++i){
            int mod = i % (2 * k);
            if(acc[mod] == n){
                ans = i;
                break;
            }
        }

        cout << ans << '\n';
    }
}
