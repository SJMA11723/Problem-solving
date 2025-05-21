/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define ff first
#define ss second

using namespace std;

const int MOD = 998244353;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        int ans = 1, cur_good = 1, cnt = s[0] == '1' ? 1 : -1;
        for(int i = 1; i < n; ++i){
            if(s[i] == '1'){
                cnt++;
                if(cnt < 0) break;
                else if(cnt == 0){
                    cur_good = 1;
                    ans += cur_good;
                    if(ans >= MOD) ans -= MOD;
                    cnt++;
                } else {
                    cnt--;
                    cur_good += cur_good;
                    if(cur_good >= MOD) cur_good -= MOD;
                    ans += cur_good;
                    if(ans >= MOD) ans -= MOD;
                }
            } else {
                cnt--;
                if(cnt > 0) break;
                else if(cnt == 0){
                    cur_good = 1;
                    ans += cur_good;
                    if(ans >= MOD) ans -= MOD;
                    cnt--;
                } else {
                    cnt++;
                    cur_good += cur_good;
                    if(cur_good >= MOD) cur_good -= MOD;
                    ans += cur_good;
                    if(ans >= MOD) ans -= MOD;
                }
            }
        }
        cout << ans << '\n';
    }
}
