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
        int k, q; cin >> k >> q;
        int mini = INT_MAX;
        while(k--){
            int x; cin >> x;
            mini = min(mini, x);
        }

        while(q--){
            int n; cin >> n;
            cout << min(n, mini - 1) << ' ';
        }
        cout << '\n';
    }
}
