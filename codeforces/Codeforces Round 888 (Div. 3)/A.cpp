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
        int n, m, k, h;
        cin >> n >> m >> k >> h;
        int ans = 0;
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            for(int i = 0; i < m; ++i)
                for(int j = 0; j < i; ++j)
                if(i != j && k * (i - j) == abs(x - h)){
                    ans++;
                    i = m;
                    break;
                }
        }
        cout << ans << '\n';
    }
}
