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
    while(n--){
        int x; cin >> x;
        int ans = 0;
        for(int i = 1; i * i <= x; ++i){
            if(x % i) continue;
            ans++;
            if(i * i != x) ans++;
        }
        cout << ans << '\n';
    }
}
