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
        int n, s, r; cin >> n >> s >> r;
        cout << s - r << ' ';
        int cnt = r % (n - 1);
        for(int i = 1; i < n; ++i) cout << r / (n - 1) + (cnt-- > 0 ? 1 : 0) << " \n"[i + 1 == n];
    }
}
