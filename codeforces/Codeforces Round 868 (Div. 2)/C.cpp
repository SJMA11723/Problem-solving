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
        map<int, int> cub;
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            for(int j = 2; j * j <= x; ++j){
                while(x % j == 0){
                    cub[j]++;
                    x /= j;
                }
            }
            if(x > 1) cub[x]++;
        }
        int primes_cnt = 0, ans = 0;
        for(auto &it : cub){
            ans += it.second / 2;
            primes_cnt += it.second % 2;
        }
        ans += primes_cnt / 3;
        cout << ans << '\n';
    }
}
