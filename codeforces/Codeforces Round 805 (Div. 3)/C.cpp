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
        int n, k; cin >> n >> k;
        map<int, vector<int>> cub;
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            cub[x].push_back(i);
        }

        while(k--){
            int a, b; cin >> a >> b;
            if(cub[a].empty() || cub[b].empty()){
                cout << "NO\n";
                continue;
            }

            if(cub[a].front() < cub[b].back()) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
