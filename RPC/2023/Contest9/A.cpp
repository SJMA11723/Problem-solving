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
    int h, k, v, s;
    cin >> h >> k >> v >> s;
    int ans = 0;
    while(h > 0){
        v += s;
        v -= max(1, v / 10);
        if(v >= k) h++;
        if(0 < v && v < k){
            h--;
            if(h == 0) v = 0;
        }
        if(v <= 0){
            h = 0;
            v = 0;
        }
        ans += v;
        if(s > 0) s--;
    }
    cout << ans << '\n';
}
