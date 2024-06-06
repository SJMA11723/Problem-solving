/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int dfs(int node, int arr[], vector<int> &cycle, bool vis[]){
    vis[node] = true;
    cycle.push_back(node);
    return 1 + (vis[arr[node]] ? 0 : dfs(arr[node], arr, cycle, vis));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
            arr[i]--;
        }

        int ans = 0;
        bool adj_in_cycle = false;
        bool vis[n] = {};
        for(int i = 0; i < n; ++i){
            if(vis[i]) continue;
            vector<int> cycle;

            ans += dfs(i, arr, cycle, vis) - 1;

            set<int> ap;
            for(int x : cycle){
                if(ap.count(x + 1) || ap.count(x - 1)) adj_in_cycle = true;
                ap.insert(x);
                //cout << "Inserted " << x + 1 << '\n';
            }
        }

        if(adj_in_cycle) ans--;
        else ans++;

        cout << ans << '\n';
    }
}
