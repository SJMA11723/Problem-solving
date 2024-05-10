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

        if(n == 1){
            cout << k << '\n';
            continue;
        }

        int64_t msb;
        for(int i = 0; i < 31; ++i){
            if(k & (1 << i)){
                msb = i;
            }
        }

        if((1 << (msb + 1)) - 1 == k){
            cout << k << " 0 ";
        } else {
            cout << (1 << msb) - 1 << ' ' << k - ((1 << msb) - 1) << ' ';
        }
        for(int i = 2; i < n; ++i) cout << "0 ";
        cout << '\n';
    }
}
