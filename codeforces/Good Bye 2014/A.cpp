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
    int n, t; cin >> n >> t;
    t--;
    int arr[n]; arr[n - 1] = 0;
    for(int i = 0; i < n - 1; ++i) cin >> arr[i];

    bool vis[n] = {};
    int cur = 0;
    while(!vis[cur]){
        vis[cur] = true;
        cur += arr[cur];
    }

    cout << (vis[t] ? "YES\n" : "NO\n");
}
