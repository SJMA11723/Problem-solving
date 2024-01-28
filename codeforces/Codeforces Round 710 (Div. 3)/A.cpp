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
        int64_t n, m, x; cin >> n >> m >> x;
        int i = (x - 1) % n, j = (x - 1) / n;
        cout << i * m + j + 1 << '\n';
    }
}
