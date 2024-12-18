/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

const string RGB = "RGB";

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        string s; cin >> s;

        int ans = INT_MAX;
        for(int r = 0; r < 3; ++r){
            for(int i = 0; i + k <= n; ++i){
                int cnt = 0;
                for(int j = 0; j < k; ++j)
                    if(s[i + j] != RGB[(j + r) % 3]) cnt++;
                ans = min(ans, cnt);
            }
        }
        cout << ans << '\n';
    }
}
