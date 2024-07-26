/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int n = s.size();
        int64_t ans = 0;
        map<int, int64_t> pref;
        int sum = 0;
        for(int i = 0; i < n; ++i){
            if(s[i] == '1') sum++;
            else sum--;

            if(!sum){
                ans += n - i;
                if(ans > MOD) ans -= MOD;
            }

            ans += 1ll * (pref[sum]) * (n - i) % MOD;
            if(ans > MOD) ans -= MOD;

            pref[sum] += i + 2;
        }

        cout << ans << '\n';
    }
}
