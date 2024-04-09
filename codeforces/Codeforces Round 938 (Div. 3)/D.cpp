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
        int n, m, k; cin >> n >> m >> k;
        int A[n], B[m];
        unordered_map<int, int> cub_b, cub_window;
        for(int i = 0; i < n; ++i) cin >> A[i];
        for(int i = 0; i < m; ++i){
            cin >> B[i];
            cub_b[B[i]]++;
            cub_window[A[i]]++;
        }

        unordered_set<int> vis;
        int match = 0, ans = 0;
        for(int i = 0; i < m; ++i){
            if(vis.count(A[i])) continue;
            vis.insert(A[i]);
            match += min(cub_window[A[i]], cub_b[A[i]]);
        }
        if(match >= k) ans++;

        for(int i = m; i < n; ++i){
            match -= min(cub_window[A[i - m]], cub_b[A[i - m]]);
            cub_window[A[i - m]]--;
            match += min(cub_window[A[i - m]], cub_b[A[i - m]]);

            match -= min(cub_window[A[i]], cub_b[A[i]]);
            cub_window[A[i]]++;
            match += min(cub_window[A[i]], cub_b[A[i]]);

            if(match >= k) ans++;
        }

        cout << ans << '\n';
    }
}
