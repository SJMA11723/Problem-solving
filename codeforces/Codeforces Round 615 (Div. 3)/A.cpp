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
        int a, b, c, n;
        cin >> a >> b >> c >> n;
        int maxi = max({a, b, c});
        if(n + a + b + c - 3 * maxi < 0 || (n + a + b + c - 3 * maxi) % 3 ) cout << "NO\n";
        else cout << "YES\n";
    }
}
