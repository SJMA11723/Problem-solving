/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> prefix_function(string s){
    int n = s.size();
    vector<int> pi(n);
    for(int i = 1; i < n; ++i){
        int j = pi[i - 1];
        while(j && s[i] != s[j]) j = pi[j - 1];
        pi[i] = j + (s[i] == s[j]);
    }
    return pi;
}

int solve(int l, int r, const string &s, vector<vector<int>> &dp){
    if(l == r) return 1;
    if(l > r) return 0;

    if(dp[l][r]) return dp[l][r];

    vector<int> pi = prefix_function(s.substr(l, r - l + 1));

    int n = r - l + 1;
    int p = r - l + 1 - pi.back();
    int res = 1e8;
    if(pi.back()) res = solve(l, l + p - 1, s, dp) + solve(r - (n % p) + 1, r, s, dp);

    for(int i = l; i < r; ++i) res = min(res, solve(l, i, s, dp) + solve(i + 1, r, s, dp));

    return dp[l][r] = res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s; cin >> s;
    while(s != "*"){
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        cout << solve(0, n - 1, s, dp) << '\n';
        cin >> s;
    }
}
