/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ordered_set l, r;
    int n; cin >> n;
    pair<int, int> arr[n];
    for(auto &p : arr) cin >> p.first;
    for(auto &p : arr) cin >> p.second;
    sort(arr, arr + n);

    for(int i = 0; i < n; ++i) r.insert({arr[i].second, i});

    int64_t ans = 0;
    for(int i = 0; i < n; ++i){
        r.erase({arr[i].second, i});
        if(l.size()) ans += 1ll * arr[i].first * l.order_of_key({arr[i].second, INT_MAX});
        if(r.size()) ans -= 1ll * arr[i].first * ((int)r.size() - r.order_of_key({arr[i].second, INT_MIN}));
        l.insert({arr[i].second, i});
    }

    cout << ans << '\n';
}
