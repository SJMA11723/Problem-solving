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
            for(int d = 2; d * d <= x; ++d){
                while(x % d == 0){
                    cub[d]++;
                    x /= d;
                }
            }
            if(x > 1) cub[x]++;
        }

        bool ok = true;
        for(auto &it : cub) ok = ok && it.second % n == 0;
        cout << (ok ? "YES\n" : "NO\n");
    }
}
