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
    int n; cin >> n;

    int64_t ans = 0;
    int cnt_ascent = 0;
    vector<int> maxs_non_ascent;
    int l[n], r[n];
    bool ascent[n] = {};
    for(int i = 0; i < n; ++i){
        bool is_ascent = false;
        int k; cin >> k;
        int prv = INT_MAX, maxi = 0, mini = INT_MAX;
        while(k--){
            int x; cin >> x;
            if(prv < x) is_ascent = true;
            prv = x;
            maxi = max(maxi, x);
            mini = min(mini, x);
        }

        l[i] = maxi;
        r[i] = mini;
        ascent[i] = is_ascent;

        if(is_ascent) cnt_ascent++, ans += n;
        else maxs_non_ascent.push_back(maxi);
    }

    ans += (n - cnt_ascent) * cnt_ascent;
    sort(all(maxs_non_ascent));
    for(int i = 0; i < n; ++i){
        if(ascent[i]) continue;
        ans += maxs_non_ascent.end() - upper_bound(all(maxs_non_ascent), r[i]);
    }

    cout << ans << '\n';
}
