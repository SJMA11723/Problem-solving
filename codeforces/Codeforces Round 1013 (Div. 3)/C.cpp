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
        if(n % 2 == 0){
            cout << "-1\n";
            continue;
        }
        if(n == 1){
            cout << "1\n";
            continue;
        }

        for(int i = 1; i <= n; i += 2) cout << i << ' ';
        for(int i = 2; i <= n; i += 2) cout << i << " \n"[i + 2 > n];
    }
}
