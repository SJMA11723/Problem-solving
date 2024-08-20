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
        if(n % 2){
            for(int i = (n + 1) / 2; 0 < i; --i) cout << i << " \n"[n == 1];
            for(int i = (n + 1) / 2 + 1; i <= n; ++i) cout << i << " \n"[i == n];
        } else cout << "-1\n";
    }
}
