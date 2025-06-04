/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define fi first
#define se second

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        int64_t arr[n];
        int64_t sum = 0, max_sum = 0;
        map<int64_t, int> one_cycle, mini;
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
            sum += arr[i];
            if(one_cycle.count(sum) == 0) one_cycle[sum] = i;
            arr[i] = sum;
            max_sum = max(max_sum, sum);
        }

        int cur_mini = INT_MAX;
        for(auto it = one_cycle.rbegin(); it != one_cycle.rend(); ++it){
            cur_mini = min(cur_mini, it->se);
            mini[it->fi] = cur_mini;
        }

        while(m--){
            int64_t x; cin >> x;
            if(one_cycle.lower_bound(x) != one_cycle.end()) cout << mini[one_cycle.lower_bound(x)->fi];
            else {
                if(sum <= 0) cout << "-1";
                else {
                    int64_t ncycles = (max(0ll, x - max_sum) + sum - 1) / sum;
                    int64_t ans = ncycles * n;
                    x -= sum * ncycles;
                    ans += mini[ one_cycle.lower_bound(x)->fi ];
                    cout << ans;
                }
            }

            cout << " \n"[!m];
        }
    }
}
