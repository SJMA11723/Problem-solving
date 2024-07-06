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
        int64_t x, y, z, k;
        cin >> x >> y >> z >> k;
        int64_t ans = 0;

        for(int xi = 1; xi <= x; ++xi){
            for(int yi = 1; yi <= y; ++yi){
                if(k % (1ll*xi*yi)) continue;
                int64_t zi = k / xi / yi;
                ans = max(ans, (x - xi + 1) * (y - yi + 1) * max(0ll, z - zi + 1));
            }
        }

        for(int xi = 1; xi <= x; ++xi){
            for(int zi = 1; zi <= z; ++zi){
                if(k % (1ll*xi*zi)) continue;
                int64_t yi = k / xi / zi;
                ans = max(ans, (x - xi + 1) * (z - zi + 1) * max(0ll, y - yi + 1));
            }
        }

        for(int yi = 1; yi <= y; ++yi){
            for(int zi = 1; zi <= z; ++zi){
                if(k % (1ll*yi*zi)) continue;
                int64_t xi = k / yi / zi;
                ans = max(ans, (y - yi + 1) * (z - zi + 1) * max(0ll, x - xi + 1));
            }
        }

        cout << ans << '\n';
    }
}
