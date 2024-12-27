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
        int64_t n; cin >> n;
        int cnt = 0;
        while(n > 3){
            n /= 4;
            cnt++;
        }
        cout << (1ll << cnt) << '\n';
    }
}
