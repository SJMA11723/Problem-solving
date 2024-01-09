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
        int n, x; cin >> n >> x;

        if(n % x) cout << "-1\n";
        else {
            vector<int> primes;
            int tmp = n / x;
            for(int i = 2; i * i <= tmp; ++i){
                while(tmp % i == 0){
                    primes.push_back(i);
                    tmp /= i;
                }
            }
            if(tmp > 1) primes.push_back(tmp);

            int ans[n + 1] = {};
            ans[1] = x;
            int last = x;
            for(int p : primes){
                ans[last] = p * last;
                last *= p;
            }
            ans[n] = 1;

            for(int i = 1; i <= n; ++i){
                if(ans[i]) cout << ans[i] << ' ';
                else cout << i << ' ';
            }
            cout << '\n';
        }
    }
}
