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
    int n, m, k; cin >> n >> k >> m;
    vector<int> cub[m];
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        cub[x % m].push_back(x);
    }
    for(int i = 0; i < m; ++i){
        if(cub[i].size() >= k){
            cout << "Yes\n";
            cub[i].resize(k);
            for(int x : cub[i]) cout << x << ' ';
            cout << '\n';
            return 0;
        }
    }
    cout << "No\n";
}
