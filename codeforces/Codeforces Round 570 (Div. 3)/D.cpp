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
    int q; cin >> q;
    while(q--){
        int n; cin >> n;
        int cnt[n] = {};
        for(int i = 0; i < n; ++i){
            int x; cin >> x; x--;
            cnt[x]++;
        }
        sort(cnt, cnt + n);
        bool used_type[n] = {};
        bool used_quant[n + 1] = {};
        for(int i = 0; i < n; ++i){
            if(!used_quant[ cnt[i] ]){
                used_quant[ cnt[i] ] = true;
                used_type[i] = true;
            }
        }

        int prv = n;

        for(int i = n - 1; 0 <= i; --i){
            if(used_type[i]) continue;

            while(0 <= prv && (used_quant[prv] || prv > cnt[i])) prv--;

            if(0 <= prv) used_quant[ prv ] = true;
        }

        int ans = 0;
        for(int i = 1; i <= n; ++i) ans += i * used_quant[i];

        cout << ans << '\n';
    }
}
