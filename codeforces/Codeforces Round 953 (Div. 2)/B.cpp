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
        int n, a, b; cin >> n >> a >> b;
        int k;
        if(a >= b) k = 0;
        else k = min(n, b - a);

        cout << 1ll * (n - k) * a + 1ll * k * (b + 1) - 1ll * k * (k + 1) / 2 << '\n';
    }
}
