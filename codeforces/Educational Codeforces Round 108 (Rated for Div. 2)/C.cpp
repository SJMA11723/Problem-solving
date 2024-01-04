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
        int U[n];
        vector<int64_t> skills[n + 1];
        for(int i = 0; i < n; ++i) cin >> U[i];
        for(int i = 0; i < n; ++i){
            int s; cin >> s;
            skills[U[i]].push_back(s);
        }

        int64_t ans[n + 1] = {};
        for(int i = 1; i <= n; ++i){
            sort(skills[i].begin(), skills[i].end());
            for(int j = (int)skills[i].size() - 2; 0 <= j; --j) skills[i][j] += skills[i][j + 1];
            for(int k = 1; k <= skills[i].size(); ++k) ans[k] += skills[i][skills[i].size() % k];
        }

        for(int i = 1; i <= n; ++i) cout << ans[i] << ' ';
        cout << '\n';
    }
}
