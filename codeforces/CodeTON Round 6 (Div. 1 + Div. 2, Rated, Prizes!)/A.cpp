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
        int n, k, x; cin >> n >> k >> x;
        if(k - 1 > x || n < k) cout << "-1\n";
        else cout << k * (k - 1) / 2 + (n - k) * (x == k ? x - 1 : x) << '\n';
    }
}
