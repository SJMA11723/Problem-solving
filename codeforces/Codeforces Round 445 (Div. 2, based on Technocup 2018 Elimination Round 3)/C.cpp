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
    int n; cin >> n;
    map<int, int> cnt;
    cnt[0]++;
    for(int i = 1; i <= n; ++i){
        int x; cin >> x;
        if(cnt.count(x)){
            cnt[x]--;
            cnt[i]++;
            if(!cnt[x]) cnt.erase(x);
        } else cnt[i]++;
    }

    int ans = 0;
    for(auto &it : cnt) ans += it.second;
    cout << ans << '\n';
}
