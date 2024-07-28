/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXVAL 200000

using namespace std;

vector<int> get_arr(const vector<pair<int, int>> &freq, const int rep){
    vector<int> res;
    for(auto [f, v] : freq){
        int cnt = 0;
        while(f / (cnt + 1) >= rep) cnt++;

        while(cnt--) res.push_back(v);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k; cin >> n >> k;
    int freq[MAXVAL + 1] = {};
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        freq[x]++;
    }

    vector<pair<int, int>> arr;
    for(int i = 1; i <= MAXVAL; ++i) if(freq[i]) arr.push_back({freq[i], i});

    sort(arr.begin(), arr.end(), greater<pair<int, int>>());

    int l = 0, r = n + 1;
    while(l < r){
        int mid = l + (r - l) / 2;
        vector<int> t = get_arr(arr, mid);
        if(t.size() < k) r = mid;
        else l = mid + 1;
    }

    vector<int> ans = get_arr(arr, l - 1);

    for(int i = 0; i < k; ++i) cout << ans[i] << " \n"[i + 1 == k];
}
