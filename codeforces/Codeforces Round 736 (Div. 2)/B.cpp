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
        string hi, lo;
        cin >> hi >> lo;
        int ans = 0;
        bool used[n] = {};
        for(int i = 0; i < n; ++i){
            if(lo[i] == '0') continue;

            if(i && !used[i - 1] && hi[i - 1] == '1'){
                ans++;
                used[i - 1] = true;
            } else if(hi[i] == '0'){
                ans++;
                used[i] = true;
            } else if(i + 1 < n && !used[i + 1] && hi[i + 1] == '1'){
                ans++;
                used[i + 1] = true;
            }
        }
        cout << ans << '\n';
    }
}
