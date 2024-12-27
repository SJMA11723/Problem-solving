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
        int n, m, k; cin >> n >> m >> k;
        int a[m];
        for(int &x : a){
            cin >> x;
            x--;
        }

        bool ap[n] = {};
        for(int i = 0; i < k; ++i){
            int x; cin >> x;
            x--;
            ap[x] = true;
        }

        string ans(m, '0');
        if(k == n - 1){
            for(int i = 0; i < m; ++i){
                if(!ap[a[i]]){
                    ans[i] = '1';
                }
            }
        } else if(k == n) ans = string(m, '1');

        cout << ans << '\n';
    }
}
