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
        int64_t n, m; cin >> n >> m;
        int64_t tmp = n, power = 2;
        int cnt_2 = 0, cnt_5 = 0;
        while(n % power == 0){
            cnt_2++;
            power *= 2;
        }

        power = 5;
        while(n % power == 0){
            cnt_5++;
            power *= 5;
        }

        int mini = min(cnt_2, cnt_5);
        cnt_2 -= mini;
        cnt_5 -= mini;

        int64_t ans = 1;
        for(int i = 0; i < cnt_5 && ans * 2 <= m; ++i) ans *= 2;
        for(int i = 0; i < cnt_2 && ans * 5 <= m; ++i) ans *= 5;

        while(ans * 10 <= m) ans *= 10;

        cout << m / ans * ans * n << '\n';
    }
}
