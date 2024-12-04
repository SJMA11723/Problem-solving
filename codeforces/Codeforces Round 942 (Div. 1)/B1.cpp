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
        int n, m; cin >> n >> m;
        int ans = 0;
        for(int b = 1; b <= m; ++b){
            for(int a = b; a <= n; a += b){
                if((a / b + 1) % b == 0) ans++;
            }
        }
        cout << ans << '\n';
    }
}
