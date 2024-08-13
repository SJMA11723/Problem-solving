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
        bool vis[n + 2] = {}, ok = true;
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            if(!i){
                vis[x] = true;
                continue;
            }

            if(vis[x] || (!vis[x - 1] && !vis[x + 1])) ok = false;
            vis[x] = true;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}
