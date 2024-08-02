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
    if(m % n){
        cout << "-1\n";
        return 0;
    }

    m /= n;

    int ans = 0;
    while(m % 2 == 0) m /= 2, ans++;
    while(m % 3 == 0) m /= 3, ans++;
    if(m > 1){
        cout << "-1\n";
        return 0;
    }
    cout << ans << '\n';
}
