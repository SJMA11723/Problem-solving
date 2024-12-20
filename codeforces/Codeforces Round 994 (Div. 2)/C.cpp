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
        int n, x, y; cin >> n >> x >> y;
        set<int> no[n + 1];
        for(int i = 1; i <= n; ++i){
            int cur = 0;
            while(no[i].count(cur)) cur++;
            cout << cur << " \n"[i == n];
            //for(int x : no[i]) cout << x << ' '; cout << '\n';

            if(i < n) no[i + 1].insert(cur);
            else no[1].insert(cur);

            if(i == 1) no[n].insert(cur);
            else no[i - 1].insert(cur);

            if(i == x) no[y].insert(cur);
            if(i == y) no[x].insert(cur);
        }
    }
}
