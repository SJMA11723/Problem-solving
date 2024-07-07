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
        int64_t n; cin >> n;
        int ans = -2;
        bool cinco = false, cero = false;
        while(n){
            ans++;
            if(n % 10 == 0){
                if(cero) break;
                cero = true;
            } else if(n % 10 == 5){
                if(cero) break;
                cinco = true;
            } else if(n % 10 == 2 && cinco) break;
            else if(n % 10 == 7 && cinco) break;
            n /= 10;
        }
        cout << ans << '\n';
    }
}
