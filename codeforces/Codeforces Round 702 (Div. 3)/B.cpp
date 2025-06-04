/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define fi first
#define se second

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int cnt[3] = {};
        int target = n / 3;
        while(n--){
            int x; cin >> x;
            cnt[x % 3]++;
        }

        int ans = 0;
        for(int i = 0; i < 6; ++i){
            int r = i % 3;
            if(cnt[r] > target){
                cnt[(r + 1) % 3] += cnt[r] - target;
                ans += cnt[r] - target;
                cnt[r] = target;
            }
        }
        cout << ans << '\n';
    }
}
