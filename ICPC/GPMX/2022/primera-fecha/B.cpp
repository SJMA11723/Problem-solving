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
    int n, k; cin >> n >> k;
    vector<int> graph[n + 1];
    for(int i = 1; i < n; ++i){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bool printed[n + 1] = {};
    int vis[n + 1];
    memset(vis, k + 1, sizeof(vis));
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(1);

    int cnt = 1;
    while(pq.size()){
        int node = pq.top();
        pq.pop();

        if(printed[node]) continue;

        cout << node;
        if(cnt < n) cout << ' ';
        else cout << '\n';
        printed[node] = true;
        cnt++;

        queue<pair<int, int>> q;
        q.push({node, 0});
        vis[node] = 0;
        //cout << "hola\n";

        while(q.size()){
            auto [act, d] = q.front();
            q.pop();

            if(k <= d) continue;

            for(int v : graph[act]){
                if(vis[v] < d + 1) continue;

                vis[v] = d + 1;
                q.push({v, d + 1});
                pq.push(v);
            }
        }
    }
}
