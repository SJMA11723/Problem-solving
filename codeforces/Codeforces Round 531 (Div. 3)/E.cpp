/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    map<int, vector<int>> cub;
    int arr[n];
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        cub[x].push_back(i);
        arr[i] = x;
    }

    bool vis[n] = {};
    int cnt = 0;
    for(int i = 0; i < n; ++i){
        if(vis[i]) continue;
        cnt++;
        int last = i;
        int cur = i;

        for(int j = i; j <= last; ++j){
            if(vis[j]) continue;
            vis[j] = true;

            for(int idx : cub[arr[j]]){
                last = max(last, idx);
                vis[idx] = true;
            }
        }
    }

    cnt--;
    int ans = 1;
    for(int i = 0; i < cnt; ++i) ans = ans * 2 % MOD;
    cout << ans << '\n';
}
