/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
* LinkedIn: https://www.linkedin.com/in/jorgetzab/
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    for(int tt = 1; tt <= t; ++tt){
        long long l, n, ans = 0, dist = 0;
        cin >> l >> n;
        char dir = 'C';
        while(n--){
            long long d;
            char c;
            cin >> d >> c;
            if(c == dir){
                dist += d;
            } else {
                if(dist - d <= 0){
                    if(dir == 'C') dir = 'A';
                    else dir = 'C';
                }
                dist = abs(dist - d);
            }
            ans += dist / l;
            dist %= l;
        }
        cout << "Case #" << tt << ": " << ans << '\n';
    }
}
