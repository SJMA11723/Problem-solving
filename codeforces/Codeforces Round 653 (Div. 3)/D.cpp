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
        map<int, int> cnt;
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            cnt[(k - (x % k)) % k]++;
        }
        cnt.erase(0);

        int64_t ans = 0;
        int x = 0;
        while(cnt.size()){
            auto lwb = cnt.lower_bound(x);
            if(lwb == cnt.end()){
                ans += k - x;
                x = 0;
                continue;
            }

            ans += lwb->first - x + 1;
            x = lwb->first + 1;
            lwb->second--;
            if(lwb->second == 0) cnt.erase(lwb);
        }

        cout << ans << '\n';
    }
}
