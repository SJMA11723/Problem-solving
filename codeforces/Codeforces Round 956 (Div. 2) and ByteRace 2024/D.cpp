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
        vector< pair<int, int> > oa(n), ob(n);
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            oa[i] = {x, i};
        }

        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            ob[i] = {x, i};
        }

        sort(oa.begin(), oa.end());
        sort(ob.begin(), ob.end());

        bool ok = true;
        vector<int> a(n), b(n);
        for(int i = 0; i < n; ++i){
            a[oa[i].second] = i;
            b[ob[i].second] = i;

            ok = ok && oa[i].first == ob[i].first;
        }

        if(!ok){
            cout << "NO\n";
            continue;
        }

        bool vis[n] = {};
        int cnt_a = 0;
        for(int i = 0; i < n; ++i){
            if(vis[i]) continue;
            int act = i, swaps = 0;
            while(!vis[act]){
                vis[act] = true;
                swaps++;
                act = a[act];
            }
            cnt_a += swaps - 1;
        }

        memset(vis, 0, sizeof(vis));
        int cnt_b = 0;
        for(int i = 0; i < n; ++i){
            if(vis[i]) continue;

            int act = i, swaps = 0;
            while(!vis[act]){
                vis[act] = true;
                swaps++;
                act = b[act];
            }
            cnt_b += swaps - 1;
        }

        cout << ((cnt_a % 2) == (cnt_b % 2) ? "YES\n" : "NO\n");
    }
}
