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
        int cub[101] = {};
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            cub[x]++;
        }

        int ans = 0;
        for(int i = 0; i < 101; ++i){
            if(cub[i] < k) ans += cub[i];
            else {
                ans = k - 1;
                break;
            }
        }
        cout << ans << '\n';
    }
}
