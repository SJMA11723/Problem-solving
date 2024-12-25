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
    set<int> vis;
    queue<pair<int, int>> q;
    int x[n];
    for(int i = 0; i < n; ++i){
        cin >> x[i];
        q.push({x[i], 0});
        vis.insert(x[i]);
    }

    int64_t sum = 0;
    while(q.size()){
        int u = q.front().first;
        int d = q.front().second;
        q.pop();

        sum += d;

        if(vis.size() == n + m) continue;

        if(vis.size() < n + m && !vis.count(u + 1)){
            vis.insert(u + 1);
            q.push({u + 1, d + 1});
        }

        if(vis.size() < n + m && !vis.count(u - 1)){
            vis.insert(u - 1);
            q.push({u - 1, d + 1});
        }
    }

    for(int i = 0; i < n; ++i) vis.erase(x[i]);

    cout << sum << '\n';
    for(int y : vis) cout << y << " \n"[y == *vis.rbegin()];
}
