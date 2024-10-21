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
        bool vis[n + 1] = {};
        int cnt = 0;
        for(int i = 0; i < 2 * n; ++i){
            int x; cin >> x;
            if(!vis[x]){
                cout << x << " \n"[cnt + 1 == n];
                cnt++;
                vis[x] = true;
            }
        }
    }
}
