/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

bool comp(pair<vector<int>, int64_t> &a,  pair<vector<int>, int64_t> &b){
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        pair<vector<int>, int64_t> arr[n];
        for(int i = 0; i < n; ++i){
            arr[i].first.resize(m);
            int64_t sum = 0;
            for(int &x : arr[i].first) cin >> x, sum += x;
            arr[i].second = sum;
        }
        sort(arr, arr + n, comp);

        int64_t ans = 0;
        int pos = 0;
        for(int i = n - 1; 0 <= i; --i){
            for(int &x : arr[i].first){
                ans += 1ll * x * (n * m - pos);
                pos++;
            }
        }
        cout << ans << '\n';
    }
}
