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
    int d = 0, digits = 0, tmp = n;
    while(tmp){
        d = tmp % 10;
        tmp /= 10;
        digits++;
    }

    int ans = 10 * (digits - 1) + d - 1;
    int cnt = 0, cnt2 = 0, maxCnt = 0;
    tmp = n;
    while(tmp){
        cnt2++;
        if( d <= (tmp % 10) ) cnt++;
        if(9 < tmp){
            if(d < tmp % 10)
                maxCnt = cnt2;
            else if(d == tmp % 10)
                maxCnt = cnt;

        }
        tmp /= 10;
    }
    if(digits - 1 == maxCnt) ans++;
    if(n < 10) ans++;

    cout << ans << '\n';
}
