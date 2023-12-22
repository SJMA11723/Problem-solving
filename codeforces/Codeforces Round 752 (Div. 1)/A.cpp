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
        long long l = 1;
        bool ok = true;
        for(int i = 1; i <= n; ++i){
            int x; cin >> x;
            l = lcm(l, i + 1);
            if(x % 2 == 0 && x % l == 0) ok = false;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}
