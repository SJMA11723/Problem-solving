/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct suff{
    int idx, ord;
    string s;
    bool operator<(const suff &b){
        return s < b.s;
    }
};

bool comp(const suff &a, const suff &b){
    return a.idx < b.idx;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        vector<suff> arr;
        for(int i = 0; i < n; ++i) arr.push_back({i, 0, s.substr(i)});
        sort(arr.begin(), arr.end());

        for(int i = 0; i < n; ++i){
            arr[i].ord = i;
        }

        sort(arr.begin(), arr.end(), comp);

        int dp[n] = {};
        for(int i = 0; i < n; ++i){
            dp[i] = 0;
            int idx = -1;
            //cout << i << ' ' << arr[i].s << ' ';
            for(int j = 0; j < i; ++j){
                if(arr[j].ord > arr[i].ord) continue;
                if(dp[i] < dp[j]){
                    idx = j;
                    dp[i] = dp[j];
                }
            }

            //cout << idx << ' ';
            int cnt = 0;
            if(idx != -1){
                for(int k = 0; k < min(arr[i].s.size(), arr[idx].s.size()); ++k)
                    if(arr[idx].s[k] < arr[i].s[k]) break;
                    else cnt++;
            }
            dp[i] += n - arr[i].idx - cnt;
            //cout << dp[i] << '\n';
        }

        cout << *max_element(dp, dp + n) << '\n';
    }
}
