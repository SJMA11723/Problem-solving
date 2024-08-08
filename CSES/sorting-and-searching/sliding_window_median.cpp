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
    int n, k; cin >> n >> k;
    int arr[n];
    for(int &x : arr) cin >> x;
    ordered_set mset;
    for(int i = 0; i < k; ++i) mset.insert({arr[i], i});

    cout << mset.find_by_order((k - 1) / 2)->first << " \n"[k == n];
    for(int i = k; i < n; ++i){
        mset.erase({arr[i - k], i - k});
        mset.insert({arr[i], i});
        cout << mset.find_by_order((k - 1) / 2)->first << " \n"[i + 1 == n];
    }
}
