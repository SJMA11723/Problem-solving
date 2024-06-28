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
        int ans = 0;
        map<int, int> pending;
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            if(pending.count(INT_MAX ^ x)){
                auto it = pending.find(INT_MAX ^ x);
                it->second--;
                if(!it->second) pending.erase(it);
            }
            else {
                pending[x]++;
                ans++;
            }
        }

        cout << ans << '\n';
    }
}
