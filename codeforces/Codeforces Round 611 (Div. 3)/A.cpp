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
        int hh, mm; cin >> hh >> mm;
        int ans = 0;
        if(mm) ans += 60 - mm, hh++;
        ans += (24 - hh) * 60;
        cout << ans << '\n';
    }
}
