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
    int n, k; cin >> n >> k;
    unordered_map<int, int> cub[10];
    unordered_map<int, int> cub_prev[10];
    int64_t ans = 0;
    int x;
    for(int i = 0; i < n; ++i){
        cin >> x;

        int64_t tmp = x / 10;
        int d = 0;
        while(tmp){
            d++;
            tmp /= 10;
        }

        x %= k;
        int rem = x ? k - x : 0;
        if(cub[d].count(rem)) ans += cub[d][rem];

        tmp = 10ll * x % k;
        for(int j = 0; j < 10; ++j){
            cub[j][tmp]++;

            if(tmp) {if(cub_prev[j].count(k - tmp)) ans += cub_prev[j][k - tmp];}
            else if(cub_prev[j].count(0)) ans += cub_prev[j][0];

            tmp = tmp * 10 % k;
        }

        cub_prev[d][x]++;
    }

    cout << ans << '\n';
}
