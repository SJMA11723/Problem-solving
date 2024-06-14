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
        for(int i = k + 1; i < n; ++i) cout << n - i + k + 1 << ' ';
        for(int i = 0; i < k; ++i) cout << i + 1 << ' ';
        cout << k + 1 << '\n';
    }
}
