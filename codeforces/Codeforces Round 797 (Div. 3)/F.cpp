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
        string str; cin >> str;
        int P[n];
        for(int i = 0; i < n; ++i){
            int x; cin >> x; x--;
            P[x] = i;
        }

        bool vis[n] = {};
        int64_t ans = 1;
        for(int i = 0; i < n; ++i){
            if(vis[i]) continue;
            string cycle;
            int pos = i;
            while(!vis[pos]){
                vis[pos] = true;
                cycle += str[pos];
                pos = P[pos];
            }

            string T = cycle + cycle;
            int64_t min_shift = 1;
            for(int j = 1; j <= cycle.size(); ++j)
                if(cycle == T.substr(j, cycle.size())){
                    min_shift = j;
                    break;
                }

            ans = ans / gcd(ans, min_shift) * min_shift;
        }
        cout << ans << '\n';
    }
}
