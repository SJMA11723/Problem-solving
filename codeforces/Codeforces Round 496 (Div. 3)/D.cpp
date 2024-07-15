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
    string n; cin >> n;
    int ans = 0, d_prev = 0, d_prev_prev = 0;
    for(int i = 0; i < n.size(); ++i){
        int d = n[i] - '0';
        if(d % 3 == 0 || (d + d_prev) % 3 == 0 || (d + d_prev + d_prev_prev) % 3 == 0){
            ans++;
            d_prev = d_prev_prev = 0;
        } else {
            d_prev_prev = d_prev;
            d_prev = d;
        }
    }
    cout << ans << '\n';
}
