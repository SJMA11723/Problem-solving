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
    int n, m; cin >> n >> m;
    int ans = 0;
    while(n && m){
        if(n >= max(2, m)){
            n -= 2;
            m--;
        } else if(m >= 2){
            m -= 2;
            n--;
        } else break;
        ans++;
    }
    cout << ans << '\n';
}
