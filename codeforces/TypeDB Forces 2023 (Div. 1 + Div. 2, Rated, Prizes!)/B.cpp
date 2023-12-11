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
        vector<pair<int, int>> primes;
        for(int i = 2; i * i <= n; ++i){
            int cnt = 0;
            while(n % i == 0){
                cnt++;
                n /= i;
            }
            if(cnt) primes.push_back({cnt, i});
        }
        if(n > 1) primes.push_back({1, n});
        sort(primes.begin(), primes.end());
        reverse(primes.begin(), primes.end());

        int ans = 0;
        while(primes.size()){
            int p = primes.back().first;
            int a = 1;
            for(auto &it : primes){
                it.first -= p;
                a *= it.second;
            }
            ans += a * p;
            while(primes.size() && !primes.back().first)
                primes.pop_back();
        }
        cout << ans << '\n';
    }
}
