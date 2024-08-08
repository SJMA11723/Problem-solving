/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;

    ordered_set mset;
    set<pair<int, int>> intervals;
    int l[n], r[n];
    for(int i = 0; i < n; ++i){
        cin >> l[i] >> r[i];
        mset.insert(l[i]);
        mset.insert(r[i]);
        mset.insert(r[i] + 1);
        intervals.insert({l[i], r[i]});
    }

    set<int> acc[mset.size() + 1];
    for(int i = 0; i < n; ++i){
        acc[mset.order_of_key(l[i])].insert(i);
        acc[mset.order_of_key(r[i] + 1)].insert(i);
    }

    bool nonredundant[n] = {};
    set<int> pending;
    for(int i = 0; i < mset.size(); ++i){
        for(int x : acc[i]){
            if(pending.count(x)) pending.erase(x);
            else pending.insert(x);
        }

        if(pending.size() == 1) nonredundant[*pending.begin()] = true;
    }

    int ans = -1;
    for(int i = 0; i < n; ++i) if(!nonredundant[i]) ans = i + 1;
    cout << ans << '\n';
}
