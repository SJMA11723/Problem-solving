#include <bits/stdc++.h>
#define is_on(n, i) ((n) & (1 << (i)))

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int sides[5] = {4, 6, 8, 12, 20};
    vector<pair<int, int>> dices;
    for(int i = 0; i < 5; ++i){
        int x; cin >> x;
        if(x) dices.push_back({x, i});
    }

    for(int i = 1; i < dices.size(); ++i) dices[i].first += dices[i - 1].first;
    int n = dices.back().first;
    long double dp[501][n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    for(int s = 1; s <= 500; ++s){
        for(int i = 1; i <= n; ++i){
            int dice_id = 0;
            int l = 0, r = dices.size();
            while(l < r){
                int mid = l + (r - l) / 2;
                if(dices[mid].first < i) l = mid + 1;
                else r = mid;
            }
            dice_id = dices[l].second;

            for(int j = 1; j <= sides[dice_id]; ++j)
                if(s - j >= 0) dp[s][i] += dp[s - j][i - 1];
            dp[s][i] /= sides[dice_id];
        }
    }

    vector<pair<long double, int>> ans;
    for(int s = 1; s <= 500; ++s) if(dp[s][n]) ans.push_back({dp[s][n], s});
    sort(ans.begin(), ans.end(), greater<pair<long double, int>>());

    for(int i = 0; i < ans.size(); ++i) cout << ans[i].second << " \n"[i + 1 == ans.size()];
}
