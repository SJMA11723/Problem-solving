/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXVAL 1000000
#define is_on(n, i) ((n) & (1 << (i)))

using namespace std;

const int MOD = 998244353;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int lp[MAXVAL + 1] = {};
    for(int i = 2; i <= MAXVAL; ++i){
        if(lp[i]) continue;
        lp[i] = i;
        for(int64_t j = 1ll * i * i; j <= MAXVAL; j += i) lp[j] = i;
    }

    int n; cin >> n;
    int cnt[MAXVAL + 1] = {}, x;
    cin >> x;
    for(int d = 1; d * d <= x; ++d){
        if(x % d) continue;
        cnt[d] = 1;
        if(d * d != x) cnt[x / d] = 1;
    }

    int ans = 1;
    for(int i = 1; i < n; ++i){
        cin >> x;
        vector<int> primes;
        int tmpx = x;
        while(tmpx > 1){
            primes.push_back(lp[tmpx]);
            while(tmpx % primes.back() == 0) tmpx /= primes.back();
        }

        ans = 0;
        int lim = 1 << primes.size();
        for(int mask = 1; mask < lim; ++mask){
            int mlcm = 1;
            for(int j = 0; j < primes.size(); ++j)
            if(is_on(mask, j)) mlcm *= primes[j];

            ans += cnt[mlcm] * (__builtin_parity(mask) ? 1 : -1);
            if(ans < 0) ans += MOD;
            else if(ans >= MOD) ans -= MOD;
        }

        for(int d = 1; d * d <= x; ++d){
            if(x % d) continue;
            cnt[d] += ans;
            if(cnt[d] >= MOD) cnt[d] -= MOD;
            if(d * d != x){
                cnt[x / d] += ans;
                if(cnt[x / d] >= MOD) cnt[x / d] -= MOD;
            }
        }
    }
    cout << ans << '\n';
}
