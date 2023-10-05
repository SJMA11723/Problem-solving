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
        int cub[10001] = {};
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            cub[x]++;
        }
        int ans = 0, cnt = 0;
        for(int i = 0; i < 10001; ++i){
            if(cub[i]) ans++;
            if(cub[i] > 1 && cub[i] % 2 == 0) cnt++;
        }
        if(cnt % 2) ans--;
        cout << ans << '\n';
    }
}
