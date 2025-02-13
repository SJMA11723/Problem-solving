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
        int cnt_primes[n + 1] = {}, cnt_semiprimes[n + 1] = {};
        int cnt[n + 1] = {}, arr[n];
        for(int &x : arr){
            cin >> x;
            cnt[x]++;
        }

        int64_t ans = 0;
        for(int x : arr){
            vector<int> primes;
            int tmp = x;
            for(int d = 2; d * d <= x; ++d){
                while(x % d == 0){
                    primes.push_back(d);
                    x /= d;
                }
            }
            if(x > 1) primes.push_back(x);

            x = tmp;
            if(primes.size() == 1) cnt_primes[x]++;
            else if(primes.size() == 2){
                for(int d = 1; d * d <= x; ++d){
                    if(x % d) continue;
                    ans += cnt[d];
                    if(d * d != x) ans += cnt[x / d];
                }
                ans -= cnt[x];
                cnt_semiprimes[x]++;
            }
        }
        int sum = 0;
        for(int i = 2; i <= n; ++i){
            ans += 1ll * sum * cnt_primes[i];
            sum += cnt_primes[i];

            ans += 1ll * cnt_semiprimes[i] * (cnt_semiprimes[i] - 1) / 2 + cnt_semiprimes[i];
        }

        cout << ans << '\n';
    }
}
