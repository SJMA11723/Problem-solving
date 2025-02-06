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
    int n; cin >> n;
    int a[n], b[n];
    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;

    ordered_set mset;
    for(int i = 0; i < n; ++i) mset.insert({b[i] - a[i], i});

    int64_t ans = 0;
    for(int i = 0; i < n; ++i){
        mset.erase({b[i] - a[i], i});
        ans += mset.order_of_key({a[i] - b[i] - 1, INT_MAX});
    }
    cout << ans << '\n';
}
