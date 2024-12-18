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
        if(n == 1) cout << "1\n";
        else if(n == 2) cout << "2 1\n";
        else if(n == 3) cout << "2 3 1\n";
        else {
            int even = 0, odd = -1;
            for(int i = 0; i < n; ++i){
                if(i + 2 == n && n % 2) break;
                if(i % 2) odd += 2, cout << odd << " \n"[i + 1 == n];
                else even += 2, cout << even << " \n"[i + 1 == n];
            }
            if(n % 2) cout << n << ' ' << n - 2 << '\n';
        }
    }
}
