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
        int n, m; cin >> n >> m;
        int deg[n] = {};
        int a[n];
        for(int &x : a) cin >> x;
        vector<pair<int, int>> edges;
        for(int i = 0; i < m; ++i){
            int a, b; cin >> a >> b;
            a--, b--;
            edges.push_back({a, b});
            deg[a]++;
            deg[b]++;
        }

        if(m % 2 == 0){
            cout << "0\n";
            continue;
        }

        int ans = INT_MAX;
        int mini = 0;
        for(int i = 0; i < n; ++i){
            if(a[i] < a[mini]) mini = i;
            if(deg[i] % 2 == 0) continue;
            ans = min(ans, a[i]);
        }

        for(auto [u, v] : edges)
            if(deg[u] % 2 == deg[v] % 2) ans = min(ans, a[u] + a[v]);

        cout << ans << '\n';
    }
}
