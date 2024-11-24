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
        int ans; cin >> ans;
        for(int i = 1; i < n; ++i){
            int a; cin >> a;
            ans = (ans / a + 1) * a;
        }
        cout << ans << '\n';
    }
}
