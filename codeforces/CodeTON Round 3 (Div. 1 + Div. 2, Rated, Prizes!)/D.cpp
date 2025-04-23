/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define is_on(n, i) ((n) & (1 << (i)))

using namespace std;

const int MOD = 998244353;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        int a[n];
        for(int &x : a) cin >> x;
        bool ok = true;
        for(int i = 1; i < n; ++i) ok &= a[i - 1] % a[i] == 0;
        if(!ok){
            cout << "0\n";
            continue;
        }

        vector<int> primes;
        int tmp = a[0];
        for(int i = 2; i * i <= tmp; ++i){
            if(tmp % i) continue;

            primes.push_back(i);
            while(tmp % i == 0) tmp /= i;
        }
        if(tmp > 1) primes.push_back(tmp);

        int ans = 1;
        for(int i = 1; i < n; ++i){
            int maxb = m / a[i];

            int num = a[i - 1] / a[i];
            vector<int> primes2;
            for(int p : primes)
            if(num % p == 0) primes2.push_back(p);

            int lim = 1 << primes2.size();
            int coprimes_num = maxb;
            for(int mask = 1; mask < lim; ++mask){
                int mlcm = 1;
                for(int j = 0; j < primes2.size() && mlcm <= num; ++j){
                    if(is_on(mask, j)){
                        mlcm *= primes2[j];
                    }
                }

                coprimes_num += maxb / mlcm * (__builtin_parity(mask) ? -1 : 1);
            }

            ans = 1ll * ans * coprimes_num % MOD;
        }

        cout << ans << '\n';
    }
}
