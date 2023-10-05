/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int multDigits(int n){
    int res = 1;
    while(n){
        res *= n % 10;
        n /= 10;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int ans = 0;
        while(n > 9){
            ans++;
            n = multDigits(n);
        }
        cout << ans << '\n';
    }
}
