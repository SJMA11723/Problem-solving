/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define is_on(n, i) ((n) & (1ll << (i)))

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s; cin >> s;
    int lim = 1 << (s.size() - 1);
    int64_t ans = stoll(s);
    for(int mask = 1; mask < lim; ++mask){
        int last = 0;
        for(int i = 0; i < s.size() - 1; ++i){
            if(is_on(mask, i)){
                ans += stoll(s.substr(last, i + 1 - last));
                last = i + 1;
            }
        }
        if(last < s.size()) ans += stoll(s.substr(last));
    }
    cout << ans << '\n';
}
