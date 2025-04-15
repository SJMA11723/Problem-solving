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
        int ans[2 * n] = {};
        bool ap[2 * n] = {};
        for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j){
            int x; cin >> x;
            ans[i + j - 1] = x;
            ap[x - 1] = true;
        }
        ans[0] = min_element(ap, ap + 2 * n) - ap + 1;
        for(int i = 0; i < 2 * n; ++i) cout << ans[i] << " \n"[i + 1 == 2 * n];
    }
}
