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
        bool impar = false;
        int cnt_impar = INT_MAX;
        int cnt_par = INT_MAX;
        while(n--){
            int x; cin >> x;
            if(x % 2){
                impar = !impar;
                int cnt = 0;
                while(x % 2){
                    x /= 2;
                    cnt++;
                }
                cnt_impar = min(cnt_impar, cnt);
            } else {
                int cnt = 0;
                while(x % 2 == 0){
                    x /= 2;
                    cnt++;
                }
                cnt_par = min(cnt_par, cnt);
            }
        }
        int ans;
        if(!impar) ans = 0;
        else ans = min(cnt_impar, cnt_par);
        cout << ans << '\n';
    }
}
