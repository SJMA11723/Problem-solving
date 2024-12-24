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
    int n; cin >> n;
    int a[n];
    for(int &x : a) cin >> x;
    vector<int> graph[n];
    for(int i = 0; i < n; ++i){
        int v = i - a[i];
        if(0 <= v) graph[v].push_back(i);
        v = i + a[i];
        if(v < n) graph[v].push_back(i);
    }

    int ans[n];
    fill(ans, ans + n, -1);

    bool vis[n] = {};
    queue<pair<int, int>> q;
    for(int i = 0; i < n; ++i){
        if(a[i] % 2){
            q.push({i, 0});
            vis[i] = true;
        }
    }
    while(q.size()){
        int u = q.front().first;
        int d = q.front().second;
        q.pop();

        for(int v : graph[u]){
            if(vis[v]) continue;
            if(a[v] % 2 == 0) ans[v] = d + 1;
            vis[v] = true;
            q.push({v, d + 1});
        }
    }

    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < n; ++i){
        if(a[i] % 2 == 0){
            q.push({i, 0});
            vis[i] = true;
        }
    }
    while(q.size()){
        int u = q.front().first;
        int d = q.front().second;
        q.pop();

        for(int v : graph[u]){
            if(vis[v]) continue;
            if(a[v] % 2) ans[v] = d + 1;
            vis[v] = true;
            q.push({v, d + 1});
        }
    }

    for(int i = 0; i < n; ++i) cout << ans[i] << " \n"[i + 1 == n];
}
