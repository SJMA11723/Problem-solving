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
    int q; cin >> q;
    while(q--){
        int64_t n, a, b; cin >> n >> a >> b;
        cout << n / 2 * min(2 * a, b) + (n % 2) * a << '\n';
    }
}
