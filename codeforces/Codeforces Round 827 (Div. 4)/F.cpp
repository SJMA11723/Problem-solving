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
        int64_t len_s = 1, len_t = 1;
        bool s_greater_a = false, t_greater_a = false;
        int64_t s_cnt_a = 1, t_cnt_a = 1;
        int q; cin >> q;
        while(q--){
            int64_t d, k;
            string x;
            cin >> d >> k >> x;
            bool ok = t_greater_a;
            for(char c : x){
                if(d == 1){
                    len_s += k;
                    if(c > 'a') s_greater_a = true;
                    else s_cnt_a += k;
                } else {
                    len_t += k;
                    if(c > 'a') t_greater_a = true, ok = true;
                    else t_cnt_a += k;
                }
            }
            if(!ok && (!s_greater_a || s_cnt_a >= t_cnt_a) ) ok = len_s < len_t;

            cout << (ok ? "YES\n" : "NO\n");
        }
    }
}
