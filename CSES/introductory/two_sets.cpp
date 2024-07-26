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
    int64_t n; cin >> n;
    if(n * (n + 1) % 4) cout << "NO\n";
    else {
        cout << "YES\n";
        int64_t idx = 0;
        for(int64_t i = 1; i <= n; ++i){
            idx = i;
            if(i * (i + 1) / 2 > n * (n + 1) / 4) break;
        }

        int pending = 0;
        cout << idx - 1 << '\n';
        for(int i = 1; i <= idx; ++i){
            if(idx * (idx + 1) / 2 - i == n * (n + 1) / 4) pending = i;
            else cout << i << ' ';
        } cout << '\n';

        cout << n - idx + 1 << '\n';
        if(pending) cout << pending << ' ';
        for(int i = idx + 1; i <= n; ++i) cout << i << ' ';
        cout << '\n';
    }
}
