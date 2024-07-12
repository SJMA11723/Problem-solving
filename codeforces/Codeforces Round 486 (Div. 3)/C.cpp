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
    int k; cin >> k;
    map<int, vector<pair<int, int>>> cub;
    pair<int, int> l(-1, -1), r;

    vector<int> arr[k];
    ordered_set sums;
    for(int s = 0; s < k; ++s){
        int n; cin >> n;
        arr[s].resize(n);
        int sum = 0;
        for(int &x : arr[s]){
            cin >> x;
            sum += x;
        }

        for(int i = 0; i < n; ++i) sums.insert(sum - arr[s][i]);
    }


    vector<pair<int, int>> candidates[sums.size() + 10];
    for(int s = 0; s < k; ++s){
        int sum = 0;
        for(int &x : arr[s]) sum += x;

        for(int i = 0; i < arr[s].size(); ++i){
            if(l.first == -1){
                int idx_sum = sums.order_of_key(sum - arr[s][i]);
                for(auto [idx, pos] : candidates[idx_sum]){
                    if(idx != s + 1){
                        l = {s + 1, i + 1};
                        r = {idx, pos};
                        break;
                    }
                }
            } else break;
        }

        for(int i = 0; i < arr[s].size(); ++i){
            int idx_sum = sums.order_of_key(sum - arr[s][i]);
            candidates[idx_sum].push_back({s + 1, i + 1});
        }
    }

    if(l.first != -1){
        cout << "YES\n";
        cout << l.first << ' ' << l.second << '\n';
        cout << r.first << ' ' << r.second << '\n';
    } else cout << "NO\n";
}
