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
    int t;  cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n];
        for(int &x : a) cin >> x;
        bool ok = true;
        for(int i = 0; i + 2 < n; ++i){
            if(a[i] < 0){
                ok = false;
                break;
            }
            int cnt = a[i];
            a[i] = 0;
            a[i + 1] -= 2 * cnt;
            a[i + 2] -= cnt;
        }
        if(a[n - 2] || a[n - 1]) ok = false;
        cout << (ok ? "YES\n" : "NO\n");
    }
}
