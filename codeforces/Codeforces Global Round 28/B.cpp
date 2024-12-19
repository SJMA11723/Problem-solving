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
        int ans[n] = {};
        int nxt = 1;
        for(int i = k - 1; i < n; i += k) ans[i] = nxt++;
        for(int i = 0; i < n; ++i)
            if(!ans[i]) ans[i] = nxt++;

        for(int i = 0; i < n; ++i) cout << ans[i] << " \n"[i + 1 == n];
    }
}
