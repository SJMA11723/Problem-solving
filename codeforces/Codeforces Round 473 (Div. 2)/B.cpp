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
    int n, k, m; cin >> n >> k >> m;
    string arr[n];
    for(string &s : arr) cin >> s;

    int cost[n];
    for(int &x : cost) cin >> x;

    map<int, int> min_cost;
    map<string, int> group;
    while(k--){
        int t; cin >> t;
        min_cost[k] = INT_MAX;
        while(t--){
            int idx; cin >> idx; idx--;
            group[arr[idx]] = k;
            min_cost[k] = min(min_cost[k], cost[idx]);
        }
    }

    int64_t ans = 0;
    for(int i = 0; i < m; ++i){
        string s; cin >> s;
        ans += min_cost[group[s]];
    }
    cout << ans << '\n';
}
