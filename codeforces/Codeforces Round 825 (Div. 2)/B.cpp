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
        int a[n];
        for(int i = 0; i < n; ++i) cin >> a[i];
        int b[n + 1]; b[0] = a[0];
        for(int i = 1; i < n; ++i) b[i] = a[i] * a[i - 1] / gcd(a[i], a[i - 1]);
        b[n] = a[n - 1];
        bool ok = true;
        for(int i = 0; i < n; ++i)
            if(a[i] != gcd(b[i], b[i + 1]))
                ok = false;
        cout << (ok ? "YES\n" : "NO\n");
    }
}
