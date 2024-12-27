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
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    int ans = 0;
    vector<int> pending;
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        x %= (a + b);
        if(x && x <= a) ans++;
        else pending.push_back(x ? x : a + b);
    }
    sort(pending.begin(), pending.end());

    for(int x : pending){
        int cnt = (x + a - 1) / a;
        cnt--;
        if(cnt <= k){
            k -= cnt;
            ans++;
        } else break;
    }

    cout << ans << '\n';
}
