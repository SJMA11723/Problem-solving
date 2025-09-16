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
    int X, Y; cin >> X >> Y;
    int h, v; cin >> h >> v;
    int64_t ans = 1ll * h * v + 1;
    pair<int, int> H[h];
    for(auto &p : H) cin >> p.first >> p.second;
    sort(H, H + h);

    ordered_set mset;
    for(int i = 0; i < h; ++i){
        int from, to;
        tie(from, to) = H[i];
        ans += (int)mset.size() - mset.order_of_key({to, i}) + 1;
        mset.insert({to, i});
    }


    pair<int, int> V[v];
    for(auto &p : V) cin >> p.first >> p.second;
    sort(V, V + v);

    mset.clear();
    for(int i = 0; i < v; ++i){
        int from, to;
        tie(from, to) = V[i];
        ans += (int)mset.size() - mset.order_of_key({to, i}) + 1;
        mset.insert({to, i});
    }

    cout << ans << '\n';
}