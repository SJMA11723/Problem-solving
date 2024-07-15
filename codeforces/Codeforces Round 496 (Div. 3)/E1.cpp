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
    int p[n], idx_m;
    for(int i = 0; i < n; ++i){
        cin >> p[i];
        if(p[i] == m) idx_m = i;
    }

    map<int, int> cub;
    int less_m = 0, greater_m = 0;
    for(int i = idx_m; 0 <= i; --i){
        if(p[i] > m) greater_m++;
        else if(p[i] < m) less_m++;
        cub[greater_m - less_m]++;
    }

    int64_t ans = 0;
    less_m = greater_m = 0;
    for(int i = idx_m; i < n; ++i){
        if(p[i] > m) greater_m++;
        else if(p[i] < m) less_m++;

        int diff = greater_m - less_m;
        ans += cub[-diff] + cub[1 - diff];
    }
    cout << ans << '\n';
}
