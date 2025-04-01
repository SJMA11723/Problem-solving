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
        int cnt[10] = {}, ans = 0;
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            cnt[x]++;
            if(cnt[0] >= 3 && cnt[1] >= 1 && cnt[2] >= 2 && cnt[3] >= 1 && cnt[5] >= 1 && !ans){
                ans = i + 1;
            }
        }
        cout << ans << '\n';
    }
}
