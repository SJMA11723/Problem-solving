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
    int b; cin >> b;
    bool arr_b[n] = {};
    for(int i = 0; i < b; ++i){
        int idx; cin >> idx;
        arr_b[idx] = true;
    }

    int g; cin >> g;
    bool arr_g[m] = {};
    for(int i = 0; i < g; ++i){
        int idx; cin >> idx;
        arr_g[idx] = true;
    }

    for(int i = 0; i <= 10000; ++i)
        arr_b[i % n] = arr_g[i % m] = arr_b[i % n] || arr_g[i % m];

    int cnt = 0;
    for(int i = 0; i < n; ++i) cnt += arr_b[i];
    for(int i = 0; i < m; ++i) cnt += arr_g[i];
    cout << (cnt == n + m ? "Yes\n" : "No\n");
}
