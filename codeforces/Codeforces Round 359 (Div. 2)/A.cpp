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
    int64_t x; cin >> x;
    int ans_c = 0;
    while(n--){
        char c; cin >> c;
        int d; cin >> d;
        if(c == '+') x += d;
        else {
            if(d <= x) x -= d;
            else ans_c++;
        }
    }
    cout << x << ' ' << ans_c << '\n';
}
