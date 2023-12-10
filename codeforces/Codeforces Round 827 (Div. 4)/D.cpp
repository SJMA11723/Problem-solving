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
        vector<int> idx(1001);
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            idx[x] = i + 1;
        }
        int ans = -1;
        for(int i = 1; i < 1001; ++i){
            if(!idx[i]) continue;
            for(int j = i; j < 1001; ++j){
                if(!idx[j]) continue;

                if(__gcd(i, j) == 1)
                    ans = max(ans, idx[i] + idx[j]);
            }
        }
        cout << ans << '\n';
    }
}
