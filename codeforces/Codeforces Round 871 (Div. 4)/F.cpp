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
        vector<int> graph[n + 1];
        int deg[n + 1] = {};
        while(m--){
            int a, b; cin >> a >> b;
            deg[a]++;
            deg[b]++;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        bool ap[n + 1] = {};
        int cnt_leaves = 0, cnt_second = 0;
        for(int i = 1; i <= n; ++i){
            if(deg[i] > 1) continue;

            cnt_leaves++;
            if(!ap[graph[i][0]]) cnt_second++;
            ap[graph[i][0]] = true;
        }

        cout << cnt_second << ' ' << cnt_leaves / cnt_second << '\n';
    }
}
