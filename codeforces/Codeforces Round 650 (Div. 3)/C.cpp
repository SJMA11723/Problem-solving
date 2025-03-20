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
        int cnt = 0, ans = 0;
        bool one = false;
        for(int i = 0; i < n; ++i){
            char c; cin >> c;
            if(c == '0') cnt++;
            else {
                ans += (max(0, cnt - k - k * one) + k) / (k + 1);
                cnt = 0;
                one = true;
            }
        }
        ans += (max(0, cnt - k * one) + k) / (k + 1);
        cout << ans << '\n';
    }
}
