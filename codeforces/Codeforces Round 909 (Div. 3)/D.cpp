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
        map<int, int64_t> cub;
        for(int i = 0; i < n; ++i){
            int a; cin >> a;
            cub[a]++;
        }

        int64_t ans = cub[1] * cub[2];
        for(auto &it : cub)
            ans += it.second * (it.second - 1) / 2;
        cout << ans << '\n';
    }
}
