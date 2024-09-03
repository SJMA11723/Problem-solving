#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    int arr[n];
    for(int &x : arr) cin >> x;

    const int S = accumulate(arr, arr + n, 0);

    if(S % 2){
        cout << "-1\n";
        return 0;
    }

    bool dp[n][S + 1];
    memset(dp, 0, sizeof(dp));

    vector<char> ans[n][S + 1];
    dp[0][0] = true;
    dp[0][arr[0]] = true;
    ans[0][arr[0]].push_back(0);

    for(int i = 1; i < n; ++i){
        dp[i][0] = true;
        for(int s = 0; s <= S; ++s){
            dp[i][s] = dp[i - 1][s];
            ans[i][s] = ans[i - 1][s];

            if(arr[i] <= s && !dp[i][s]){
                if(dp[i - 1][s - arr[i]]){
                    dp[i][s] = true;
                    ans[i][s] = ans[i - 1][s - arr[i]];
                    ans[i][s].push_back(i);
                }
            }
        }
    }

    if(dp[n - 1][S / 2]){
        bool ap[n] = {};
        vector<char> alice;
        for(int i : ans[n - 1][S / 2]){
            ap[i] = true;
            alice.push_back(i);
        }
        vector<char> bob;
        for(int i = 0; i < n; ++i) if(!ap[i]) bob.push_back(i);

        int sa = 0, sb = 0;
        while(sa + sb != S){
            if(sa <= sb){
                sa += arr[alice.back()];
                cout << arr[alice.back()] << " \n"[sa + sb == S];
                alice.pop_back();
            } else {
                sb += arr[bob.back()];
                cout << arr[bob.back()] << " \n"[sa + sb == S];
                bob.pop_back();
            }
        }
    } else cout << "-1\n";
}
