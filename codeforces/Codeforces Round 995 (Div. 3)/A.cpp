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
        int a[n], b[n];
        for(int &x : a) cin >> x;
        for(int &x : b) cin >> x;
        int ans = a[n - 1];
        for(int i = 0; i + 1 < n; ++i){
            if(a[i] > b[i + 1]) ans += a[i] - b[i + 1];
        }
        cout << ans << '\n';
    }
}
