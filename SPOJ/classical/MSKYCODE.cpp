/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXVAL 10000

using namespace std;

int64_t binom(int n, int k){
    if(n < 0 || k < 0 || n < k) return 0;
    int64_t res = 1;
    for(int i = 0; i < k; ++i){
        res *= n - i;
        res /= i + 1;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> primes;
    for(int i = 2; i <= MAXVAL; ++i){
        bool prime = true;
        for(int d = 2; d * d <= i; ++d){
            if(i % d == 0){
                prime = false; break;
            }
        }
        if(prime) primes.push_back(i);
    }

    int n;
    while(cin >> n){
        int cnt[MAXVAL + 1] = {}, maxi = 0;
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            cnt[x]++;
            maxi = max(maxi, x);
        }

        int cnt_multiples[maxi + 1] = {};
        for(int i = 2; i <= maxi; ++i)
        for(int j = i; j <= maxi; j += i) cnt_multiples[i] += cnt[j];

        int64_t ans = binom(n, 4);

        for(int i1 = 0; i1 < primes.size() && primes[i1] <= maxi; ++i1){
            int mlcm = primes[i1];
            ans -= binom(cnt_multiples[mlcm], 4);
            for(int i2 = i1 + 1; i2 < primes.size() && mlcm * primes[i2] <= maxi; ++i2){
                mlcm *= primes[i2];
                ans += binom(cnt_multiples[mlcm], 4);
                for(int i3 = i2 + 1; i3 < primes.size() &&  mlcm * primes[i3] <= maxi; ++i3){
                    mlcm *= primes[i3];
                    ans -= binom(cnt_multiples[mlcm], 4);
                    for(int i4 = i3 + 1; i4 < primes.size() &&  mlcm * primes[i4] <= maxi; ++i4){
                        mlcm *= primes[i4];
                        ans += binom(cnt_multiples[mlcm], 4);
                        for(int i5 = i4 + 1; i5 < primes.size() &&  mlcm * primes[i5] <= maxi; ++i5){
                            mlcm *= primes[i5];
                            ans -= binom(cnt_multiples[mlcm], 4);
                            for(int i6 = i5 + 1; i6 < primes.size() &&  mlcm * primes[i6] <= maxi; ++i6){
                                mlcm *= primes[i6];
                                ans += binom(cnt_multiples[mlcm], 4);
                                mlcm /= primes[i6];
                            }
                            mlcm /= primes[i5];
                        }
                        mlcm /= primes[i4];
                    }
                    mlcm /= primes[i3];
                }
                mlcm /= primes[i2];
            }
        }

        cout << ans << '\n';
    }
}
