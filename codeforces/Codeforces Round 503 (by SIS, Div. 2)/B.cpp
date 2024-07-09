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
    int n; cin >> n;
    int p[n];
    for(int &x : p) cin >> x, x--;

    bool vis[n] = {};
    for(int i = 0; i < n; ++i){
        memset(vis, 0, sizeof(vis));
        int cur = i;
        while(!vis[cur]){
            vis[cur] = true;
            cur = p[cur];
        }
        cout << cur + 1 << " \n"[i + 1 == n];
    }
}
