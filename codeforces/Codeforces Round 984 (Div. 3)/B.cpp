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
        int n, k; cin >> n >> k;
        int64_t cnt[k] = {};
        for(int i = 0; i < k; ++i){
            int b, c; cin >> b >> c;
            b--;
            cnt[b] += c;
        }
        sort(cnt, cnt + k, greater<int64_t>());
        cout << accumulate(cnt, cnt + min(k, n), 0ll) << '\n';
    }
}
