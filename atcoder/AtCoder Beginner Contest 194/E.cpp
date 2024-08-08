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
    int arr[n];
    for(int &x : arr) cin >> x;
    set<int> pending;
    for(int i = 0; i <= n; ++i) pending.insert(i);

    int cub[n] = {};
    for(int i = 0; i < m; ++i){
        pending.erase(arr[i]);
        cub[arr[i]]++;
    }

    int ans = *pending.begin();
    for(int i = m; i < n; ++i){
        cub[arr[i - m]]--;
        if(!cub[arr[i - m]]) pending.insert(arr[i - m]);

        pending.erase(arr[i]);
        cub[arr[i]]--;

        ans = min(ans, *pending.begin());
    }
    cout << ans << '\n';
}
