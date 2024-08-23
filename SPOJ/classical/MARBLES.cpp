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
        int64_t ans = 1;
        for(int i = k; i < n; ++i){
            ans *= i;
            ans /= i - k + 1;
        }
        cout << ans << '\n';
    }
}
