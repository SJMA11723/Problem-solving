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
        int ans = -1;
        for(int i = 0; i <= n; ++i){
            if(i * (i - 1) + (n - i) * (n - i - 1) == 2 * k){
                ans = i;
                break;
            }
        }
        if(ans == -1) cout << "NO\n";
        else {
            cout << "YES\n";
            for(int i = 0; i < ans; ++i) cout << "1 ";
            for(int i = 0; i < n - ans; ++i) cout << "-1 ";
            cout << '\n';
        }
    }
}
