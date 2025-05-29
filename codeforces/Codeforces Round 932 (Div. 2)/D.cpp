/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define ff first
#define ss second

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, c; cin >> n >> c;
        int64_t ans = 1ll * (c + 1) * (c + 2) / 2;
        int cnt_odd = 0, cnt_even = 0;
        for(int i = 0; i < n; ++i){
            int s; cin >> s;

            /// x - y = s_j, x + y = s_i
            if(s & 1) ans += cnt_odd++;
            else ans += cnt_even++;

            ans -= (s + 2) / 2; /// x + y = s;
            ans -= c - s; /// x - y = s
        }
        cout << ans << '\n';
    }
}
