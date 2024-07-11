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
    int ans = 0, cnt = 0;
    for(int i = 0; i < n; ++i){
        char c; cin >> c;
        if(c == 'x') cnt++;
        else {
            ans += max(0, cnt - 2);
            cnt = 0;
        }
    }
    ans += max(0, cnt - 2);
    cout << ans << '\n';
}
