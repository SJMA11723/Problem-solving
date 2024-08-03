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
    int n, b, a; cin >> n >> b >> a;
    bool s[n];
    for(bool &x : s) cin >> x;

    int ans = 0, cnt_a = a, cnt_b = b;
    for(int i = 0; i < n && (cnt_b || cnt_a); ++i){
        if(!cnt_b){
            cnt_a--;
        } else if(!cnt_a){
            cnt_b--;
            if(s[i]) cnt_a = min(cnt_a + 1, a);
        } else {
            if(s[i]){
                if(cnt_a == a) cnt_a--;
                else {
                    cnt_b--;
                    cnt_a = min(cnt_a + 1, a);
                }
            } else cnt_a--;
        }
        ans++;
    }
    cout << ans << '\n';
}
