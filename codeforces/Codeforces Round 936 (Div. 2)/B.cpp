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
        int n, k; cin >> n >> k;
        int64_t sum = 0, max_sum = 0, sum_act = 0;
        for(int i = 0; i < n; ++i){
            int64_t x; cin >> x;
            sum += x;
            sum_act = max(sum_act + x, x);
            max_sum = max(max_sum, sum_act);
        }
        int64_t max_0 = max_sum;
        for(int i = 0; i < k; ++i) max_sum = max_sum * 2 % MOD;
        cout << (sum + max_sum - max_0 + MOD*(int64_t)1e8) % MOD << '\n';
    }
}
