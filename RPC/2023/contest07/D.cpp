/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define isOn(n, i) ( (n) & (1 << i) )

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k; cin >> n >> k;
    int lim = 1 << n, ans = 0;
    for(int i = 0; i < lim; ++i){
        bool ok = true;
        for(int j = 0; j < n; j++){
            bool bit = isOn(i, j);
            int con = 0;
            for(int jj = j; jj < n; ++jj){
                if( bit == bool(isOn(i, jj - 1)) ) con++;
                else break;
            }
            if(con > k) ok = false;
        }
        if(ok) ans++;
    }
    cout << ans << '\n';
}
