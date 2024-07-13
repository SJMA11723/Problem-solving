/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ifstream cin("helpcross.in");
    ofstream cout("helpcross.out");

    int c, n; cin >> c >> n;
    multiset<int> chickens;
    for(int i = 0; i < c; ++i){
        int x; cin >> x;
        chickens.insert(x);
    }

    pair<int, int> arr[n];
    for(pair<int, int> &p : arr) cin >> p.first >> p.second;
    sort(arr, arr + n, comp);

    int ans = 0;
    for(int i = 0; i < n; ++i){
        auto lwb = chickens.lower_bound(arr[i].first);
        if(lwb != chickens.end() && *lwb <= arr[i].second){
            ans++;
            chickens.erase(lwb);
        }
    }
    cout << ans << '\n';
}
