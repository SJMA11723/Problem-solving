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
        vector<int> cub[n + 1];
        int arr[n];
        for(int i = 0; i < n; ++i){
            int x; cin >> x; arr[i] = x;
            cub[x].push_back(i);
        }

        int ans[n] = {};
        vector<int> single;
        for(int i = 1; i <= n; ++i)
            if(cub[i].size() >= k){
                for(int j = 0; j < k; ++j) ans[cub[i][j]] = j + 1;
            } else if(cub[i].size()) single.insert(single.end(), cub[i].begin(), cub[i].end());
        single.resize(single.size() / k * k);

        for(int i = 0; i < single.size(); ++i)
            ans[single[i]] = i % k + 1;

        for(int i = 0; i < n; ++i) cout << ans[i] << " \n"[i + 1 == n];
    }
}
