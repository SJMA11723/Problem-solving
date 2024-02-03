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
        bool ok = false;
        int64_t sum = 0;
        int cnt = 0;
        for(int i = 0; i < n; ++i){
            int64_t x; cin >> x;
            sum += abs(x);
            if(x < 0) ok = true;
            if(ok && x > 0){
                ok = false;
                cnt++;
            }
        }
        if(ok) cnt++;
        cout << sum << ' ' << cnt << '\n';
    }
}
