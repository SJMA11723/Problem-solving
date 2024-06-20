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
        if(k <= 4 * n - 4) cout << (k + 1) / 2 << '\n';
        else cout << (k - k % (4 * n - 4) + 1) / 2 + k % (4 * n - 4) << '\n';
    }
}
