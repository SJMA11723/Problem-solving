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
        int n, k; cin >> n >> k;
        map<int, vector<int>> res;
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            res[x % k].push_back(x);
        }

        bool mid = false, ok = true;
        int64_t ans = 0;
        for(auto &it : res){
            if(it.second.size() % 2){
                if(mid || n % 2 == 0){
                    ok = false;
                    break;
                }
                mid = true;
            }

            sort(it.second.begin(), it.second.end());

            int64_t sum = 0;
            if(it.second.size() % 2 && it.second.size() > 1){
                int64_t pref[it.second.size()] = {};
                int64_t suff[it.second.size()] = {};

                pref[1] = 1ll * (it.second[1] - it.second[0]) / k;
                for(int i = 3; i < it.second.size(); i += 2)
                    pref[i] = 1ll * (it.second[i] - it.second[i - 1]) / k + pref[i - 2];

                for(int i = (int)it.second.size() - 2; 0 <= i; i -= 2)
                    suff[i] = 1ll * (it.second[i + 1] - it.second[i]) / k + (i + 2 < it.second.size() ? suff[i + 2] : 0);

                int64_t mini = LLONG_MAX;
                for(int i = 0; i < it.second.size(); i += 2)
                    mini = min(mini, (i ? pref[i - 1] : 0) + (i + 1 < it.second.size() ? suff[i + 1] : 0));
                sum = mini;

            } else {
                for(int i = 1; i < it.second.size(); i += 2)
                    sum += 1ll * (it.second[i] - it.second[i - 1]) / k;
            }

            ans += sum;
        }

        cout << (ok ? ans : -1) << '\n';
    }
}
