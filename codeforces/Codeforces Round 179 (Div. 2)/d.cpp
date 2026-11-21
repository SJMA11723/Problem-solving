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
    int64_t adj[n][n];
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j) cin >> adj[i][j];
    int erases[n];
    for(int i = n - 1; 0 <= i; --i){
        cin >> erases[i];
        erases[i]--;
    }

    int64_t d[n][n];
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            d[i][j] = adj[i][j];

    bool ap[n] = {};
    int64_t ans[n];
    int64_t sum;
    for(int k = 0; k < n; ++k){
        ap[erases[k]] = true;

        sum = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                d[i][j] = min(d[i][j], d[i][erases[k]] + d[erases[k]][j]);
            }
        }

        for(int i = 0; i < n; ++i){
            if(!ap[i]) continue;
            for(int j = 0; j < n; ++j){
                if(!ap[j]) continue;
                if(i == j) continue;
                sum += d[i][j];
            }
        }
        ans[n - 1 - k] = sum;
    }
    for(int i = 0; i < n; ++i)
        cout << ans[i] << ' ';
    cout << '\n';
}
