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
        int ans = 0, sum = 0;
        for(int i = 2; i <= n; ++i){
            int k = n / i;
            if(i * k * (k + 1) / 2 > sum){
                sum = i * k * (k + 1) / 2;
                ans = i;
            }
        }
        cout << ans << '\n';
    }
}
