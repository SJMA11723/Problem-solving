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
        int64_t n; cin >> n;
        int ans = 0;
        while(n % 5 == 0) n = 4 * n / 5, ans++;
        while(n % 3 == 0) n = 2 * n / 3, ans++;
        while(n % 2 == 0) n /= 2, ans++;
        cout << (n == 1 ? ans : -1) << '\n';
    }
}
