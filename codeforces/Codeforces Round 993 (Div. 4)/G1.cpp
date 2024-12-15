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
        int n; cin >> n;
        int nxt[n], in_deg[n] = {};
        for(int i = 0; i < n; ++i){
            int r; cin >> r;
            nxt[i] = r - 1;
            in_deg[r - 1]++;
        }

        char vis[n] = {}, in_cycle[n] = {};
        for(int i = 0; i < n; ++i){
            if(vis[i]) continue;
            stack<int> st;
            int u = i;
            bool cycle = false;
            int init = -1;
            while(!vis[u]){
                vis[u] = 1;
                if(vis[nxt[u]] == 1){
                    cycle = true;
                    init = nxt[u];
                }
                st.push(u);
                u = nxt[u];
            }

            while(st.size()){
                u = st.top();
                vis[u] = 2;
                in_cycle[u] = cycle;
                if(init == u) cycle = false;
                st.pop();
            }
        }

        int ans = 0;
        queue<pair<int, int>> q;
        for(int i = 0; i < n; ++i)
        if(!in_deg[i]) q.push({i, 1});

        while(q.size()){
            int u, d;
            tie(u, d) = q.front();
            q.pop();

            ans = max(ans, d);

            //cout << u + 1 << ' ' << d << '\n';

            if(in_cycle[u]) continue;

            q.push({nxt[u], d + 1});
        }

        if(ans) ans++;
        else ans = 2;

        cout << ans << '\n';
    }
}
