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
        int a[n], b[n];
        for(int i = 0; i < n; ++i) cin >> a[i];

        set<int> available;
        for(int i = 0; i < n; ++i){
            cin >> b[i];
            available.insert(b[i]);
        }

        int m; cin >> m;
        int d[m];
        for(int i = 0; i < m; ++i) cin >> d[i];

        bool ok = true;
        int idx = 0, last_idx = -1;
        map<int, int> pending;
        for(int i = 0; i < n; ++i){
            if(a[i] == b[i]){
                last_idx = i;
                continue;
            }

            if(pending[b[i]]){
                pending[b[i]]--;
                last_idx = i;
                continue;
            }

            while(idx < m && d[idx] != b[i]){
                pending[d[idx]]++;
                idx++;
            }
            if(idx == m){
                ok = false;
                break;
            } else pending[d[idx++]]++;

            pending[b[i]]--;
            last_idx = i;
        }

        if(!available.count(d[m - 1]) || last_idx != n - 1) ok = false;

        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
