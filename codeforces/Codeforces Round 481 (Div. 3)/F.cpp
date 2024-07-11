/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k; cin >> n >> k;
    pair<int, int> arr[n];
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        arr[i] = {x, i};
    }

    vector<int> F[n];
    for(int i = 0; i < k; ++i){
        int a, b; cin >> a >> b;
        a--, b--;
        F[a].push_back(arr[b].first);
        F[b].push_back(arr[a].first);
    }

    for(int i = 0; i < n; ++i) sort(F[i].begin(), F[i].end());

    sort(arr, arr + n);
    int ans[n];
    for(auto [skill, i] : arr){
        int l = 0, r = n;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(arr[mid].first >= skill) r = mid;
            else l = mid + 1;
        }
        ans[i] = l - (lower_bound(F[i].begin(), F[i].end(), skill) - F[i].begin());
    }

    for(int i = 0; i < n; ++i) cout << ans[i] << " \n"[i + 1 == n];
}
