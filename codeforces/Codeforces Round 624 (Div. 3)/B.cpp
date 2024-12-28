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
        bool can_swap[n] = {};
        int a[n];
        for(int &x : a) cin >> x;
        int id = 1;
        for(int i = 0; i < m; ++i){
            int x; cin >> x;
            x--;
            can_swap[x] = true;
        }

        bool vis[n] = {};
        for(int i = 0; i < n; ++i){
            if(!can_swap[i]) continue;
            if(vis[i]) continue;

            int r = i;
            while(can_swap[r]){
                vis[r] = true;
                r++;
            } vis[r] = true;
            sort(a + i, a + r + 1);
        }

        cout << (is_sorted(a, a + n) ? "YES\n" : "NO\n");
    }
}
