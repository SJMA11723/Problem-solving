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
        if(!k){
            cout << "0\n";
            continue;
        }
        int ans = 1;
        k = max(0, k - n);
        for(int i = 1; i < n; ++i){
            if(!k) break;
            ans++;
            k = max(0, k - n + i);

            if(!k) break;
            ans++;
            k = max(0, k - n + i);
        }
        cout << ans << '\n';
    }
}
