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
        map<int, int> cub;
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            if(x % 2 == 0) cub[x]++;
        }

        int ans = 0;
        while(cub.size()){
            auto it = cub.end();
            it--;
            if(it->first / 2 % 2 == 0) cub[it->first / 2] += it->second;
            cub.erase(it);
            ans++;
        }
        cout << ans << '\n';
    }
}
