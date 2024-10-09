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
        int ans = 0, gold = 0;
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            if(x >= k) gold += x;
            else if(!x && gold) ans++, gold--;
        }
        cout << ans << '\n';
    }
}
