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
        int n, x; cin >> n >> x;
        int64_t k; cin >> k;
        string route; cin >> route;

        bool zero = false;
        for(int i = 0; i < n; ++i){
            if(route[i] == 'L') x--;
            else x++;
            k--;
            if(!x){
                zero = true;
                break;
            }
        }

        if(zero){
            int64_t ans = 1;
            for(int i = 0; i < n && k; ++i){
                if(route[i] == 'L') x--;
                else x++;
                k--;
                if(!x){
                    ans += 1 + k / (i + 1);
                    break;
                }
            }
            cout << ans << '\n';
        } else cout << "0\n";
    }
}
