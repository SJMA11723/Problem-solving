#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int64_t n, k; cin >> n >> k;
    int64_t arr[n + 1], acc[n + 1];
    acc[0] = arr[0] = 0;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
        acc[i] = acc[i - 1] + arr[i];
    }

    int64_t sum = 0;
    for(int i = 1; i <= k; ++i) sum += arr[i] * i;

    vector<pair<int64_t, int>> ans;
    ans.push_back({sum, 1});

    for(int i = k + 1; i <= n; ++i){
        sum -= acc[i - 1] - acc[i - k - 1];
        sum += arr[i] * k;
        ans.push_back({sum, i - k + 1});
    }

    sort(ans.begin(), ans.end());

    for(auto [s, i] : ans){
        cout << i << ' ' << s << '\n';
    }
}
