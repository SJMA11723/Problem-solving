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
        int n; cin >> n;
        int p[n], sorted[n];
        for(int &x : p) cin >> x;
        memcpy(sorted, p, sizeof(p));
        sort(sorted, sorted + n);

        int ans = INT_MAX;
        for(int i = 0; i < n; ++i) if(p[i] != sorted[i]) ans &= p[i];
        cout << ans << '\n';
    }
}
