/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define is_on(n, i) ((n) & (1 << (i)))

using namespace std;

vector<int> primes;

void criba(int n){
    primes.clear();
    if(n < 2) return;

    vector<bool> no_primo(n + 1);
    no_primo[0] = no_primo[1] = true;

    for(long long i = 3; i * i <= n; i += 2){
        if(no_primo[i]) continue;
        for(long long j = i * i; j <= n; j += 2 * i)
            no_primo[j] = true;
    }

    primes.push_back(2);
    for(int i = 3; i <= n; i += 2){
        if(!no_primo[i])
            primes.push_back(i);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    criba(1e6);

    int t; cin >> t;
    for(int tt = 1; tt <= t; ++tt){
        int n, k; cin >> n >> k;
        int arr[k];
        for(int &x : arr) cin >> x;

        /// 1 no es compuesto ni primo
        int cnt_primes = upper_bound(primes.begin(), primes.end(), n) - primes.begin();
        int ans = max(0, n - 1) - cnt_primes + min(k, cnt_primes);

        int lim = 1 << k;
        for(int mask = 1; mask < lim; ++mask){
            int mlcm = 1;
            for(int i = 0; i < k && mlcm <= n; ++i)
            if(is_on(mask, i)) mlcm *= arr[i];

            ans += n / mlcm * (__builtin_parity(mask) ? -1 : 1);
        }
        cout << "Case " << tt << ": " << ans << '\n';
    }
}
