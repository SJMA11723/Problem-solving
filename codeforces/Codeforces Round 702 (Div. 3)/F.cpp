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
        map<int, int> cnt;
        while(n--){
            int x; cin >> x;
            cnt[x]++;
        }

        vector<int> freqs;
        for(auto &it : cnt) freqs.pb(it.se);

        sort(all(freqs));
        int ans = INT_MAX, sum = accumulate(all(freqs), 0);

        n = freqs.size();
        for(int i = 0; i < n; ++i) ans = min(ans, sum - freqs[i] * (n - i));
        cout << ans << '\n';
    }
}
