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
        int num = 2023;
        bool ok = true;
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            if(num % x) ok = false;
            num /= x;
        }

        if(!ok) cout << "NO\n";
        else {
            cout << "YES\n";
            cout << num << ' ';
            for(int i = 1; i < k; ++i) cout << "1 ";
            cout << '\n';
        }
    }
}
