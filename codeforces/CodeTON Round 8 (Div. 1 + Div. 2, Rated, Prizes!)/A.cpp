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
        if(n == k){
            for(int i = 0; i < n; ++i) cout << "1 ";
            cout << '\n';
        } else if(k == 1){
            for(int i = 0; i < n; ++i) cout << i + 1 << ' ';
            cout << '\n';
        } else cout << "-1\n";
    }
}
