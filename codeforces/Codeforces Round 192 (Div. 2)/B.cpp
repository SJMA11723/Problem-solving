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

    int deg[n];
    fill(deg, deg + n, n - 1);
    set<pair<int, int>> forbidden_edges;
    for(int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;
        a--, b--;
        forbidden_edges.insert({min(a, b), max(a, b)});
        deg[a]--;
        deg[b]--;
    }

    set<int> pending;
    int s = 0;
    for(int i = 0; i < n; ++i){
        if(deg[s] < deg[i]) s = i;
        pending.insert(i);
    }

    queue<int> q;
    q.push(s);
    pending.erase(s);
    vector<pair<int, int>> ans;
    while(q.size()){
        int cur = q.front();
        q.pop();

        stack<int> erased;
        for(int v : pending){
            if(forbidden_edges.count({min(cur, v), max(cur, v)})) continue;
            q.push(v);
            erased.push(v);
            ans.push_back({cur + 1, v + 1});
        }

        while(erased.size()){
            pending.erase(erased.top());
            erased.pop();
        }
    }

    cout << ans.size() << '\n';
    for(auto [u, v] : ans) cout << u << ' ' << v << '\n';
}
