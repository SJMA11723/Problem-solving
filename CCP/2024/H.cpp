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
    int n; cin >> n;
    if(n < 0 || n > 99999) cout << "0\n";
    else {
        int ans = 0;
        while(n){
            ans += n % 10;
            n /= 10;
        }
        cout << ans << '\n';
    }
}
