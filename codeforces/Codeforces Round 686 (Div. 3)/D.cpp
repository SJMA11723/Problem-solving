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
        long long n; cin >> n;
        long long tmp = n, max_p = 0, max_cnt = 0, cnt = 0;
        for(long long i = 2; i * i <= tmp; ++i){
            cnt = 0;
            while(tmp % i == 0){
                tmp /= i;
                cnt++;
            }
            if(cnt > max_cnt){
                max_cnt = cnt;
                max_p = i;
            }
        }
        if(max_cnt < 1 && tmp > 1){
            max_cnt = 1;
            max_p = tmp;
        }

        long long pot = 1;
        cout << max_cnt << '\n';
        for(int i = 1; i < max_cnt; ++i){
            pot *= max_p;
            cout << max_p << ' ';
        }
        cout << n / pot << '\n';
    }
}
