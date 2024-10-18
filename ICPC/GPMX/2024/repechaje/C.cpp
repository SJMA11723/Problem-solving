#include<bits/stdc++.h>

using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int B[n + 1], P[n + 1], F[n + 1];
    for(int i = 1; i <= n; ++i) cin >> B[i];
    for(int i = 1; i <= n; ++i) cin >> P[i];
    for(int i = 1; i <= n; ++i) cin >> F[i];

    int max_p = 0, max_f = 0;
    for(int k = 1; k <= n; ++k){
        if(B[k] > 260) continue;

        int dp[n + 1][161];
        memset(dp, 0, sizeof(dp));
        int idx = 1;
        int maxi = 0;
        for(int i = 1; i <= n; ++i){
            if(idx == k) continue;

            for(int t = 1; t <= min(160, 260 - B[k]); ++t){
                dp[idx][t] = dp[idx - 1][t];
                if(t < B[idx]) continue;
                dp[idx][t] = max(dp[idx - 1][t - B[idx]] + P[idx], dp[idx][t]);
            }
            maxi = max(maxi, *max_element(dp[idx], dp[idx] + 161));
            idx++;
        }

        max_p = max(max_p, maxi + P[k]);

        /// Calcula fama
        memset(dp, 0, sizeof(dp));
        idx = 1;
        maxi = 0;
        for(int i = 1; i <= n; ++i){
            if(idx == k) continue;

            for(int t = 1; t <= min(160, 260 - B[k]); ++t){
                dp[idx][t] = dp[idx - 1][t];
                if(t < B[idx]) continue;
                dp[idx][t] = max(dp[idx - 1][t - B[idx]] + F[idx], dp[idx][t]);
            }
            maxi = max(maxi, *max_element(dp[idx], dp[idx] + 161));
            idx++;
        }
        max_f = max(max_f, maxi + F[k]);
    }

    if(max_p == max_f) cout << "EITHER\n";
    else if(max_p < max_f) cout << "FAME\n";
    else cout << "PLEASURE\n";
}
