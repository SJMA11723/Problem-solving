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
        int64_t n, b, c;
        cin >> n >> b >> c;
        if(!b){
            if(c >= n) cout << n << '\n';
            else if(c >= n - 2) cout << n - 1 << '\n';
            else cout << "-1\n";
        } else cout << max(0ll, n - (max(0ll, n - c) + b - 1) / b) << '\n';
    }
}
