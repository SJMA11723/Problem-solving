/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define fi first
#define se second

using namespace std;

const int MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s; cin >> s;
    int ans = 0, cnt_b = 0;
    reverse(all(s));
    for(char c : s){
        if(c == 'a'){
            ans += cnt_b;
            cnt_b += cnt_b;
            if(ans >= MOD) ans -= MOD;
            if(cnt_b >= MOD) cnt_b -= MOD;
        } else {
            cnt_b++;
            if(cnt_b == MOD) cnt_b = 0;
        }
    }
    cout << ans << '\n';
}
