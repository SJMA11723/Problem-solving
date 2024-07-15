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
    int n, m; cin >> n >> m;
    set<pair<int, int>> edges;
    for(int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;
        edges.insert({min(a, b), max(a, b)});
    }

    int ans = 0;
    priority_queue<pair<int, int>> q;
    q.push({0, 1});
    bool vis[n + 1] = {};
    set<int> pending;
    for(int i = 1; i <= n; ++i) pending.insert(i);

    while(q.size()){
        int cur = q.top().second;
        int w = -q.top().first;
        q.pop();

        if(vis[cur]) continue;
        vis[cur] = true;
        pending.erase(cur);
        ans += w;

        vector<int> erased;
        for(int v : pending){
            if(edges.count({min(cur, v), max(cur, v)})) continue;
            q.push({0, v});
            erased.push_back(v);
        }

        if(erased.empty() && pending.size()){
            q.push({-1, *pending.begin()});
        }

        while(erased.size()){
            pending.erase(erased.back());
            erased.pop_back();
        }
    }

    cout << ans << '\n';
}
